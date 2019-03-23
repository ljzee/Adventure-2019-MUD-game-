/////////////////////////////////////////////////////////////////////////////
//                         Single Threaded Networking
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////


#include "Server.h"
#include "User.h"
#include "UserManager.h"
#include "JSONParser.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <vector>
#include "world.h"
#include "Commander.h"
#include "CharacterController.h"
#include "RoomController.h"
#include "AssociationController.h"
#include "utils.h"
#include "constants.h"

#include "boost/algorithm/string.hpp"


using networking::Server;
using networking::Connection;
using networking::Message;


UserManager UsrMgr;
std::vector<Connection> disconnectedUsers;


struct CommandQueue {
    std::unordered_map<uintptr_t, std::deque<std::unique_ptr<Command>>> bufferedCommands;
    int heartBeatCount = 0;
    void addCommand(const Message& message, std::unique_ptr<Command> cmd) {
        auto connectionId = message.connection.id;
        auto avatarCommandDeque = bufferedCommands.find(message.connection.id);
        if(avatarCommandDeque != bufferedCommands.end()){
            avatarCommandDeque->second.push_back(std::move(cmd));
        }else{
            std::deque<std::unique_ptr<Command>> newCommandDeque;
            newCommandDeque.push_back(std::move(cmd));
            bufferedCommands.insert({connectionId, std::move(newCommandDeque)});
        }
    }
} cmdQueue;

void
onConnect(Connection c) {
    std::cout << "New connection found: " << c.id << "\n";

    User user{c};
    UsrMgr.addUser(user);
    UsrMgr.printAllUsers();

    //SEND MESSAGE TO A PARTICULAR CONNECTION LIKE THIS
    UsrMgr.sendMessage(user.getConnection(), ADMIN_CONSTANTS::WELCOME_PROMPT);

}


void
onDisconnect(Connection c) {
    std::cout << "Connection lost: " << c.id << "\n";

    UsrMgr.removeUser(c);
    UsrMgr.printAllUsers();

    disconnectedUsers.push_back(c); //disconnected users must be processed by the world to remove association
}

//required since the world has no notion that a player disconnected, the world keeps an association between conectionid and avatarid
void removeDisconnectedAssociations(World& world){
    for(auto connection : disconnectedUsers){
        world.removeAssociation(connection);
    }
}

void processCharacterCreation(Connection connection, const std::string& name, World& world){
    auto result = world.createCharacter(connection, name);
    if(result.first == World::creation_success){
        UsrMgr.setHasActiveAvatar(connection, true);
        UsrMgr.sendMessage(connection, WORLD_CONSTANTS::CHARACTER_CREATE_SUCCESS);
        std::string roomEntitiesDescription = world.placeNewCharacter(connection);
        UsrMgr.sendMessage(connection, roomEntitiesDescription);
    }else if(result.first == World::name_taken){
        UsrMgr.sendMessage(connection, WORLD_CONSTANTS::CHARACTER_NAME_TAKEN);
    }
}

void
processAuthenticatedMessages(const Message& message, World& world) {
    auto pair = SplitInitialWordAndRest(message.text);
    if(pair.first == "!LOGOUT") {
        UsrMgr.logout(message.connection);
        world.removeAssociation(message.connection);
        UsrMgr.printAllUsers();
    }else if(UsrMgr.ifHasActiveAvatar(message.connection)){
        if(pair.first == "!SWITCH"){
            UsrMgr.setHasActiveAvatar(message.connection, false);
            world.removeAssociation(message.connection);
        }else {
            cmdQueue.addCommand(message, std::move(Commander::createNewCommand(message)));
        }
    }else{
        if(pair.first == "!SELECT"){
            std::cout << "calling !SELECT" << std::endl;
            UsrMgr.setHasActiveAvatar(message.connection, true);
            UsrMgr.sendMessage(message.connection, ADMIN_CONSTANTS::SELECT_SUCCESS);
        }else if(pair.first == "!NEW"){
            processCharacterCreation(message.connection, pair.second, world);
        }else{
            UsrMgr.sendMessage(message.connection, ADMIN_CONSTANTS::SELECT_PROMPT);
        }
    }
}

void
processUnauthenticatedMessages(const Message& message, World& world) {
    auto pair = SplitInitialWordAndRest(message.text);
    if (pair.first == "!REGISTER") {
        if(UsrMgr.registerUser(message.connection, message.text)){
            UsrMgr.sendMessage(message.connection, ADMIN_CONSTANTS::SELECT_PROMPT);
        }
    } else if (pair.first == "!LOGIN") {
        if(UsrMgr.login(message.connection, message.text)){
            UsrMgr.sendMessage(message.connection, ADMIN_CONSTANTS::SELECT_PROMPT);
        }
    } else {
        UsrMgr.sendMessage(message.connection, ADMIN_CONSTANTS::WELCOME_PROMPT);
    }
}


void
processMessages(Server &server,
                const std::deque<Message> &incoming,
                bool &quit,
                World& world) {

    for (auto& message : incoming) {
        //std::cout << message.text << endl; // stores in terminal
        //UsrMgr.sendMessage(message.connection, message.text); // stores on client
        if (message.text == "quit") {
            server.disconnect(message.connection);
        } else if (message.text == "shutdown") {
            std::cout << "Shutting down.\n";
            quit = true;
        } else if (UsrMgr.isAuthenticated(message.connection)) {
            processAuthenticatedMessages(message, world);
        } else {
            processUnauthenticatedMessages(message, world);
        }
    }
}


std::string
getHTTPMessage(const char* htmlLocation) {
    if (access(htmlLocation, R_OK ) != -1) {
        std::ifstream infile{htmlLocation};
        return std::string{std::istreambuf_iterator<char>(infile),
                           std::istreambuf_iterator<char>()};

    } else {
        std::cerr << "Unable to open HTML index file:\n"
                  << htmlLocation << "\n";
        std::exit(-1);
    }
}

void executeHeartbeat(std::unique_ptr<World>& world) {
    std::cout << std::string("\nHeartbeat") + "(" << cmdQueue.heartBeatCount++ << ")" << std::endl;

    for(auto& [_, queue] : cmdQueue.bufferedCommands) {
        if (!queue.empty()) {
            auto resultMessages = queue.front()->process(world);
            queue.pop_front();
            UsrMgr.sendMessageQueue(resultMessages);
        }
    }
}

int
main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage:\n  " << argv[0] << " <port> <html response>\n"
                  << "  e.g. " << argv[0] << " 4002 ./webchat.html\n";
        return 1;
    }
    JSONParser parser;
    parser.parseAreaJsonFiles();



    bool done = false;
    unsigned short port = std::stoi(argv[1]);
    Server server{port, getHTTPMessage(argv[2]), onConnect, onDisconnect};

    std::unique_ptr<RoomController> roomController = std::make_unique<RoomController>(std::move(parser.getRooms()));
    std::unique_ptr<CharacterController> characterController = std::make_unique<CharacterController>();
    std::unique_ptr<AssociationController> associationController = std::make_unique<AssociationController>();

    std::unique_ptr<World> world = std::make_unique<World>(std::move(roomController),
                                                           std::move(characterController),
                                                           std::move(associationController));
    while (!done) {
        try {
            server.update();
        } catch (std::exception& e) {
            std::cerr << "Exception from Server update:\n"
                      << " " << e.what() << "\n\n";
            done = true;
        }
        auto incoming = server.receive();
        processMessages(server, incoming, done, *world);
        executeHeartbeat(world);
        auto outgoing = UsrMgr.buildOutgoing();
        server.send(outgoing);
        removeDisconnectedAssociations(*world);
        sleep(1);
    }

    return 0;
}

