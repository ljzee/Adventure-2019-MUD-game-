//
// Created by Dev on 2019-01-24.
//

#ifndef ADVENTURE2019_USERMANAGER_H
#define ADVENTURE2019_USERMANAGER_H

#include <unordered_map>
#include "User.h"
#include <iostream>
#include <deque>
#include "Server.h"

/**
 * UserManager Class:
 *
 * - container class to hold User objects
 * - any message incoming will be processed by this class first to determine the sender's (User) authentication status
 * - in charge of authenticating/logout a User
 *
 */

class UserManager {
public:

    //adds a new user
    void addUser(User& newUser);

    //remove a current user, on logout or disconnect
    void removeUser(const networking::Connection& con);

    //find a user, returns a copy only
    //User& findUser(const networking::Connection& con);

    //authenticate a user when user sends !LOGIN
    void simpleAuthenticate(const networking::Connection& con, const std::string& userInfo);

    //authenticate a user when user sends !LOGIN <username> <password>
    void Authenticate(const networking::Connection& con, const std::string& userInfo);

    //check if a particular connection is authenticated
    bool isAuthenticated(const networking::Connection& con);

    //logout an authenticated user
    void Logout(const networking::Connection& con);

    //send message to a particular user
    void sendMessage(const networking::Connection& con, std::string message);

    //build a deque of all messages to be sent to each user
    std::deque<networking::Message> buildOutgoing();

    void printAllUsers(); //For Testing

private:

    std::unordered_map<int, User> Users;

};


#endif //ADVENTURE2019_USERMANAGER_H
