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
#include "commander.h"

#include "boost/algorithm/string.hpp"


using networking::Server;
using networking::Connection;
using networking::Message;


UserManager UsrMgr;

void
onConnect(Connection c) {
    std::cout << "New connection found: " << c.id << "\n";

    User user{c};
    UsrMgr.addUser(user);
    UsrMgr.printAllUsers();

    //SEND MESSAGE TO A PARTICULAR CONNECTION LIKE THIS
    UsrMgr.sendMessage(user.getConnection(), "Welcome Aboard!\nLogin by typing !LOGIN <username> <password> or !REGISTER <username> <password>");

}


void
onDisconnect(Connection c) {
    std::cout << "Connection lost: " << c.id << "\n";

    UsrMgr.removeUser(c);
    UsrMgr.printAllUsers();

}

void
processAuthenticatedMessages(const Message& message, Commander& commander);
    // is LOGOUT? else it's a command
void
processUnauthenticatedMessages(const Message& message, Commander& commander);
    // is it a login or register command? does it have enough args?

void
processMessages(Server &server,
                const std::deque<Message> &incoming,
                bool &quit,
                Commander& commander) {

    for (auto& message : incoming) {
        //std::cout << message.text << endl; // stores in terminal
        //UsrMgr.sendMessage(message.connection, message.text); // stores on client
        if (message.text == "quit") {
            server.disconnect(message.connection);
        } else if (message.text == "shutdown") {
            std::cout << "Shutting down.\n";
            quit = true;
        } else if (UsrMgr.isAuthenticated(message.connection)) {
            processAuthenticatedMessages(message, commander);
        } else{
            processUnauthenticatedMessages(message, commander);
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


int
main(int argc, char* argv[]) {
    //Display the results of parsing the Area JSON file
    //JSONParser parser;
    //Area testArea = parser.generateArea();

    if (argc < 3) {
        std::cerr << "Usage:\n  " << argv[0] << " <port> <html response>\n"
                  << "  e.g. " << argv[0] << " 4002 ./webchat.html\n";
        return 1;
    }

    bool done = false;
    unsigned short port = std::stoi(argv[1]);
    Server server{port, getHTTPMessage(argv[2]), onConnect, onDisconnect};

    std::unique_ptr<World> world = std::make_unique<World>();
    Commander commander{std::move(world)};
    while (!done) {
        try {
            server.update();
        } catch (std::exception& e) {
            std::cerr << "Exception from Server update:\n"
                      << " " << e.what() << "\n\n";
            done = true;
        }
        auto incoming = server.receive();
        processMessages(server, incoming, done, commander);
        commander.executeHeartbeat(UsrMgr);
        auto outgoing = UsrMgr.buildOutgoing();
        server.send(outgoing);
        sleep(1);
    }

    return 0;
}


void
processAuthenticatedMessages(const Message& message, Commander& commander) {
    // is LOGOUT? else it's a command
    if(boost::contains(message.text, "!LOGOUT")) {
        UsrMgr.logout(message.connection);
        UsrMgr.printAllUsers();
    }else if(UsrMgr.ifHasActiveAvatar(message.connection)){
        if(boost::contains(message.text, "!SWITCH")){
            //TODO: Implement the switch of characters while in game
            UsrMgr.setHasActiveAvatar(message.connection, false);
        }else {
            commander.createNewCommand(message.connection, message.text);
        }
    }else{
        if(boost::contains(message.text, "!SELECT")){
            std::cout << "calling !SELECT" << std::endl;
            UsrMgr.setHasActiveAvatar(message.connection, true);
            UsrMgr.sendMessage(message.connection, "You've selected a character");
        }else if(boost::contains(message.text, "!NEW")){
            std::cout << "calling !NEW" << std::endl;
            //UsrMgr.setHasActiveAvatar(message.connection, true);
            UsrMgr.sendMessage(message.connection, "You've created a new character! Now call !SELECT [avatar_name] to choose a character.");
        }else{
            UsrMgr.sendMessage(message.connection, "To select an existing avatar: !SELECT [avatar_name]\nTo create a new avatar: !NEW [avatar_name]\nYour avatars: Swordmaster101, thievingBoss, swedishfish");
        }
    }
}

void
processUnauthenticatedMessages(const Message& message, Commander& commander) {
    if (boost::contains(message.text ,"!REGISTER")) {
        if(UsrMgr.registerUser(message.connection, message.text)){
            UsrMgr.sendMessage(message.connection, "To select an existing avatar: !SELECT [avatar_name]\nTo create a new avatar: !NEW [avatar_name]\nYour avatars: Swordmaster101, thievingBoss, swedishfish");
        }
    } else if (boost::contains(message.text, "!LOGIN")) {
        if(UsrMgr.login(message.connection, message.text)){
            UsrMgr.sendMessage(message.connection, "To select an existing avatar: !SELECT [avatar_name]\nTo create a new avatar: !NEW [avatar_name]\nYour avatars: Swordmaster101, thievingBoss, swedishfish");
        }
    } else {
        UsrMgr.sendMessage(message.connection, std::string("Login with !LOGIN <user> <pass> or register with !REGISTER <user> <pass>"));
    }
}
