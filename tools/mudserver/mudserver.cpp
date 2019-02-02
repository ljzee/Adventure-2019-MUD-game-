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
    UsrMgr.sendMessage(user.getConnection(), "Welcome Aboard!");
    UsrMgr.sendMessage(user.getConnection(), "Login by typing !LOGIN <username> <password>");
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
                bool &quit) {

    for (auto& message : incoming) {
        if (message.text == "quit") {
            server.disconnect(message.connection);
        } else if (message.text == "shutdown") {
            std::cout << "Shutting down.\n";
            quit = true;
        } else if (!UsrMgr.isAuthenticated(message.connection)) {
            if (boost::contains(message.text ,"!LOGIN")) {
                UsrMgr.simpleAuthenticate(message.connection, message.text);
                UsrMgr.printAllUsers();
                UsrMgr.sendMessage(message.connection, std::string("You have successfully logged in!"));
            }
        } else{
            if (boost::contains(message.text, "!LOGOUT")) {
                UsrMgr.Logout(message.connection);
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

    JSONParser j;
    j.generateArea();

    if (argc < 3) {
        std::cerr << "Usage:\n  " << argv[0] << " <port> <html response>\n"
                  << "  e.g. " << argv[0] << " 4002 ./webchat.html\n";
        return 1;
    }

    bool done = false;
    unsigned short port = std::stoi(argv[1]);
    Server server{port, getHTTPMessage(argv[2]), onConnect, onDisconnect};


    while (!done) {
        try {
            server.update();
        } catch (std::exception& e) {
            std::cerr << "Exception from Server update:\n"
                      << " " << e.what() << "\n\n";
            done = true;
        }
        auto incoming = server.receive();
        processMessages(server, incoming, done);
        auto outgoing = UsrMgr.buildOutgoing();
        server.send(outgoing);
        sleep(1);
    }

    return 0;
}

