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

    void addUser(User& newUser);

    void removeUser(const uintptr_t& conId);

    User& findUser(const uintptr_t& conId);

    void Authenticate(const uintptr_t& conId, const std::string& userInfo);

    void Logout(const uintptr_t& conId);

    std::deque<networking::Message> buildOutgoing(const std::string& log);

    void printAllUsers(); //For Testing

private:

    std::unordered_map<int, User> Users;

};


#endif //ADVENTURE2019_USERMANAGER_H
