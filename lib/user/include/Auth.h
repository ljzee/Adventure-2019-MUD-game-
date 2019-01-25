//
// Created by Andrew on 2019-01-17.
//

#ifndef ADVENTURE2019_AUTH_H
#define ADVENTURE2019_AUTH_H


#include "Server.h"
#include "client.h"
#include "ChatWindow.h"

using networking::Server
using networking::Connection
using networking::Message

/**
 *  @class Auth
 *
 *  @brief Provides the login experience on initial connection to the server.
 *
 *  This library provides client prompts to log into the server, creating a user if necessary.
 *
 *  New accounts are also the responsibility of this class, thus interaction with the User class
 *  is to be expected.
 *
 *  Messages will be called from a getMessage(id) sort of function as worked out with the team later
 */

namespace user {

    class Auth {


    public:
        /**
        *  Queries username, password, or NEW from the user. Constructs a message that the server will receive with this information.
        */
        promptLogin(ChatWindow Window);

        /**
        *  Begins authentication process given a connection's id;
        */
        authSession(Connection c);

        /**
        *  Creates an account of type User populates the instance with user-provided values, saves to file.
        */
        createUser(Connection c);

        /**
        * On successful authentication alter the user's session state with a token.
        */

    };



}

#endif //ADVENTURE2019_AUTH_H
