/////////////////////////////////////////////////////////////////////////////
//                         Single Threaded Networking
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////


#include "Server.h"
#include "World.h"
#include "User.h"
#include "UserManager.h"

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
}


void
onDisconnect(Connection c) {
    std::cout << "Connection lost: " << c.id << "\n";

    UsrMgr.removeUser(c.id);
    UsrMgr.printAllUsers();

}


std::string
processMessages(Server &server,
                World &world,
                const std::deque<Message> &incoming,
                bool &quit) {

    std::ostringstream result;

    for (auto& message : incoming) {
        if (message.text == "quit") {
            server.disconnect(message.connection);
        } else if (message.text == "shutdown") {
            std::cout << "Shutting down.\n";
            quit = true;
        } else if (boost::contains(message.text ,"!LOGIN")) {
            UsrMgr.Authenticate(message.connection.id, message.text);
            UsrMgr.printAllUsers();
            result << message.connection.id << "> " << message.text << "\n";
        } else if (boost::contains(message.text, "!LOGOUT")) {
            UsrMgr.Logout(message.connection.id);
            UsrMgr.printAllUsers();
        } else {
            world.getMessageFromServer(message.text, message.connection.id);
            result << message.connection.id << "> " << message.text << "\n";
        }
    }
    return result.str();
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
    if (argc < 3) {
        std::cerr << "Usage:\n  " << argv[0] << " <port> <html response>\n"
                  << "  e.g. " << argv[0] << " 4002 ./webchat.html\n";
        return 1;
    }

    bool done = false;
    unsigned short port = std::stoi(argv[1]);
    Server server{port, getHTTPMessage(argv[2]), onConnect, onDisconnect};
    World world{};

    while (!done) {
        try {
            server.update();
        } catch (std::exception& e) {
            std::cerr << "Exception from Server update:\n"
                      << " " << e.what() << "\n\n";
            done = true;
        }

        auto incoming = server.receive();
        auto log      = processMessages(server, world, incoming, done);
        auto outgoing = UsrMgr.buildOutgoing(log);
        server.send(outgoing);
        sleep(1);
    }

    return 0;
}

