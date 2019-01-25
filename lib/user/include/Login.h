
#ifndef ADVENTURE2019_LOGIN_H
#define ADVENTURE2019_Login_H


#include "Server.h"
#include "client.h"
#include "ChatWindow.h"

using networking::Server;
using networking::Connection;
using networking::Message;

/**
 *  @class Login
 *
 *  @brief Provides the login experience on initial connection to the server.
 *
 *  This library provides client prompts to log into the server, telling it to create  a user if necessary.
 *
 *
 */

namespace user {

    class Login {
    public:
        /**
        *  Queries username, password, or NEW from the user. Constructs a message that the server will receive with this information.
        */
        std::string promptLogin(ChatWindow& Window);
        bool validateCred(const std::string pwd);

    };
}

#endif //ADVENTURE2019_LOGIN_H
