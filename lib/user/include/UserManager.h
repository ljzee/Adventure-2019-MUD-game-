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
#include <vector>
#include "RegistrationManager.h"
#include <regex>
#include "constants.h"

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

    UserManager();

    //adds a new user
    void addUser(User& newUser);

    //remove a current user, on logout or disconnect
    void removeUser(const networking::Connection& con);

    //find a user, returns a copy only
    //User& findUser(const networking::Connection& con);

    //parse a string of credentials
    std::vector<std::string> parseCredentials(const std::string& userInfo);

    //authenticate a user when user sends !LOGIN <username> <password>
    bool login(const networking::Connection &con, const std::string &userInfo);

    //logout an authenticated user
    void logout(const networking::Connection &con);

    bool registerUser(const networking::Connection &con, const std::string& userInfo);

    //check if a particular connection is authenticated
    bool isAuthenticated(const networking::Connection& con);

    //send message to a particular user
    void sendMessage(const networking::Connection& con, const std::string& message);

    void sendMessageQueue(const std::deque<std::pair<uintptr_t, std::string>>& messageQueue);
    //build a deque of all messages to be sent to each user
    std::deque<networking::Message> buildOutgoing();

    void setHasActiveAvatar(const networking::Connection &con, bool b);

    bool ifHasActiveAvatar(const networking::Connection &con);

    void addNewCharacter(const networking::Connection &con, std::pair<std::string, int> characterNameAndId);

    int getOwnedCharacterId(const networking::Connection &con, const std::string& characterName);

    std::string getOwnedCharacterInfo(const networking::Connection &con);

    void printAllUsers(); //For Testing

private:

    std::unordered_map<uintptr_t, User> connectedUsers;
    std::unordered_map<std::string, networking::Connection> activeUsernames;
    std::unique_ptr<RegistrationManager> rManager;

};


#endif //ADVENTURE2019_USERMANAGER_H
