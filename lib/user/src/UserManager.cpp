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

void UserManager::registerUser(const networking::Connection& con, const std::string& userInfo) {
    // Call parser to parse credentials
    // String message = rManager->registerUser(username, password);
    // sendMessage(con, message);
    // find user, set username
}

//authenticate a user when user sends "!LOGIN <username> <password>
void UserManager::authenticate(const networking::Connection &con, const std::string &userInfo) {
    auto user = connectedUsers.find(con.id);
    // Call parser to parse credentials
    // std::pair<String, bool> validationResults = rManager->validateCredentials(username, password);
    // user->second.sendMessage(validationResults.first);
    // user->setAuthenticated(validationResults.second);
    // set username
}

//check if a particular connection is authenticated
bool UserManager::isAuthenticated(const networking::Connection& con) {
    auto user = connectedUsers.find(con.id);
    if (user != connectedUsers.end()) {
        return user->second.isAuthenticated();
    }
    return false; //will also return false if connection does not exist in UserManager
}


//logout an authenticated user
void UserManager::logout(const networking::Connection &con) {
    connectedUsers.erase(con.id);
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


void UserManager::printAllUsers() {
    std::cout << "Connected connectedUsers: " << std::endl;
    for (auto user : connectedUsers)
        std::cout << user.second.getConnection().id
        << " username:"
        << user.second.getUsername()
        << " authenticated:" << user.second.isAuthenticated()
        << std::endl;
}
