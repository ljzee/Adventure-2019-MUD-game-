//
// Created by Dev on 2019-01-24.
//

#include "../include/UserManager.h"
#include <regex>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include <vector>



UserManager::UserManager(){
    this->rManager = std::make_unique<RegistrationManager>();
}

void UserManager::addUser(User &newUser) {
    connectedUsers.insert({newUser.getConnection().id, newUser});
}


//remove a current user, on logout or disconnect
void UserManager::removeUser(const networking::Connection& con) {
    connectedUsers.erase(con.id);
}

//authenticate a user when user sends "!LOGIN <username> <password>
bool UserManager::login(const networking::Connection &con, const std::string &userInfo) {
    const std::string LOGIN_REGEX = "!LOGIN [a-zA-Z0-9!@#$%^&*()_+=-]+ [[a-zA-Z0-9!@#$%^&*()_+=-]+";

    if (!(std::regex_match(userInfo, std::regex(LOGIN_REGEX)))) {
        sendMessage(con, "Malformed authenticate call message.");
        return false;
    } else {
        auto userCredentials = rManager->parseCredentials(userInfo);
        auto loginResult = rManager->validateUser(userCredentials[1], userCredentials[2]);
        auto user = connectedUsers.find(con.id);
        user->second.setAuthenticated(loginResult.second);
        user->second.setUsername(userCredentials[1]);
        sendMessage(con, loginResult.first);
        return loginResult.second;
    }
}

//logout an authenticated user
void UserManager::logout(const networking::Connection &con) {
    auto user = connectedUsers.find(con.id);
    user->second.reset();
    sendMessage(con, std::string("You have successfully logged out."));
}

bool UserManager::registerUser(const networking::Connection& con, const std::string& userInfo) {
    const std::string REGISTER_REGEX = "!REGISTER [a-zA-Z0-9!@#$%^&*()_+=-]+ [[a-zA-Z0-9!@#$%^&*()_+=-]+";

    if (!(std::regex_match(userInfo, std::regex(REGISTER_REGEX)))) {
        sendMessage(con, "Malformed authenticate call message.");
        return false;
    } else {
        auto userCredentials = rManager->parseCredentials(userInfo);
        auto registerResult = rManager->registerUser(userCredentials[1], userCredentials[2]);
        auto user = connectedUsers.find(con.id);
        user->second.setAuthenticated(registerResult.second);
        user->second.setUsername(userCredentials[1]);
        sendMessage(con, registerResult.first);
        return registerResult.second;
    }
}

//check if a particular connection is authenticated
bool UserManager::isAuthenticated(const networking::Connection& con) {
    auto user = connectedUsers.find(con.id);
    if (user != connectedUsers.end()) {
        return user->second.isAuthenticated();
    }
    return false; //will also return false if connection does not exist in UserManager
}


//send message to a particular user
void UserManager::sendMessage(const networking::Connection& con, const std::string& message) {
    auto user = connectedUsers.find(con.id);
    user->second.sendMessage(message);
}

//build a deque of all messages to be sent to each user
std::deque<networking::Message> UserManager::buildOutgoing() {
    std::deque<networking::Message> outgoing;
    for (auto& [_, user]: connectedUsers) {
        if(!user.isMessageEmpty()){
            outgoing.push_back({user.getConnection(), user.getUserMessagesConcatenated()});
            user.clearMessages();
        }
    }
    return outgoing;
}

void UserManager::setUserActiveAvatarId(const networking::Connection &con, int id) {
    auto user = connectedUsers.find(con.id);
    if(user != connectedUsers.end()){
        user->second.setActiveAvatarId(id);
    }
}

int UserManager::getUserActiveAvatarId(const networking::Connection &con) {
    auto user = connectedUsers.find(con.id);
    if(user != connectedUsers.end()){
        return user->second.getActiveAvatarId();
    }
    return -1;
}

void UserManager::printAllUsers() {
    std::cout << "Connected connectedUsers: " << std::endl;
    for (auto user : connectedUsers)
        std::cout << user.second.getConnection().id
        << " username:"
        << user.second.getUsername()
        << " authenticated:" << user.second.isAuthenticated()
        << std::endl;
}
