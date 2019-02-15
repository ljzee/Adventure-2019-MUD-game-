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
#include <regex>


UserManager UsrMgr;
const std::string LOGIN_REGEX = "!LOGIN [a-zA-Z0-9!@#$%^&*()_+=-]+ [[a-zA-Z0-9!@#$%^&*()_+=-]+";
const std::string REGISTER_REGEX = "!REGISTER [a-zA-Z0-9!@#$%^&*()_+=-]+ [[a-zA-Z0-9!@#$%^&*()_+=-]+";



void
onConnect(Connection c) {
    std::cout << "New connection found: " << c.id << "\n";

    User user{c};
    UsrMgr.addUser(user);
    UsrMgr.printAllUsers();

    //SEND MESSAGE TO A PARTICULAR CONNECTION LIKE THIS
    UsrMgr.sendMessage(user.getConnection(), "Welcome Aboard!");
    UsrMgr.sendMessage(user.getConnection(), "Login by typing !LOGIN <username> <password> or !REGISTER <username> <password>");

}


void
onDisconnect(Connection c) {
    std::cout << "Connection lost: " << c.id << "\n";

    UsrMgr.removeUser(c);
    UsrMgr.printAllUsers();

}


void
processMessages(Server &server,
                const std::deque<Message> &incoming,
                bool &quit,
                World& world,
                Commander& commander) {

    for (auto& message : incoming) {
        if (message.text.at(0) != '!') {
            break;
        }

        if (message.text == "quit") {
            server.disconnect(message.connection);
        } else if (message.text == "shutdown") {
            std::cout << "Shutting down.\n";
            quit = true;
        } else if (boost::contains(message.text ,"!REGISTER")) {
            if (!(std::regex_match(message.text, std::regex(REGISTER_REGEX)))) {
                UsrMgr.sendMessage(message.connection, "Malformed authenticate call message.\n");
            } else {
                UsrMgr.registerUser(message.connection, message.text.substr(10));
                UsrMgr.printAllUsers();
            }
        } else if (boost::contains(message.text, "!LOGIN")) {
            if (!(std::regex_match(message.text, std::regex(LOGIN_REGEX)))) {
                UsrMgr.sendMessage(message.connection, "Malformed authenticate call message.\n");
            } else {
                UsrMgr.authenticate(message.connection, message.text.substr(7));
                UsrMgr.printAllUsers();
            }

        } else{
            if (boost::contains(message.text, "!LOGOUT")) {
                UsrMgr.logout(message.connection);
                UsrMgr.printAllUsers();
                UsrMgr.sendMessage(message.connection, std::string("You have successfully logged out."));
            }else{
                //SEND USER COMMANDS TO WORLD OR COMMAND PROCESSOR HERE
            }
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

    World world{};
    Commander commander{};
    commander.initializeCommandTable();
    const std::string somecommand = "say";
    commander.processCommand(5, somecommand, world);
    while (!done) {
        try {
            server.update();
        } catch (std::exception& e) {
            std::cerr << "Exception from Server update:\n"
                      << " " << e.what() << "\n\n";
            done = true;
        }
        auto incoming = server.receive();
        processMessages(server, incoming, done, world, commander);
        auto outgoing = UsrMgr.buildOutgoing();
        server.send(outgoing);
        sleep(1);
    }

    return 0;
}

