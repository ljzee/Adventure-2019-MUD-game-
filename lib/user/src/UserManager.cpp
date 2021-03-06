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
    rManager->registerUser("user","password"); //test user
}

void UserManager::addUser(User &newUser) {
    connectedUsers.insert({newUser.getConnection().id, newUser});
}


//remove a current user, on logout or disconnect
void UserManager::removeUser(const networking::Connection& con) {
    logout(con);
    connectedUsers.erase(con.id);
}

std::vector<std::string> UserManager::parseCredentials(const std::string& userInfo) {
    std::vector<std::string> credentials;
    boost::split(credentials, userInfo, boost::is_any_of(" "), boost::token_compress_on);
    return credentials;
}

//authenticate a user when user sends "!LOGIN <username> <password>
bool UserManager::login(const networking::Connection &con, const std::string &userInfo) {
    const std::string LOGIN_REGEX = "!LOGIN [a-zA-Z0-9!@#$%^&*()_+=-]+ [[a-zA-Z0-9!@#$%^&*()_+=-]+";

    if (!(std::regex_match(userInfo, std::regex(LOGIN_REGEX)))) {
        sendMessage(con, AUTH_CONSTANTS::MALFORMED);
        return false;
    }

    auto userCredentials = parseCredentials(userInfo);

    if(activeUsernames.find(userCredentials[1]) != activeUsernames.end()){
        sendMessage(con, AUTH_CONSTANTS::ALREADY_LOGGED_IN);
        return false;
    }else {
        auto loginResult = rManager->validateUser(userCredentials[1], userCredentials[2]);
        if(loginResult.second) {
            auto user = connectedUsers.find(con.id);
            user->second.setAuthenticated(loginResult.second);
            user->second.setUsername(userCredentials[1]);

            activeUsernames.insert({userCredentials[1], con});
        }
        sendMessage(con, loginResult.first);
        return loginResult.second;
    }

}

//logout an authenticated user
void UserManager::logout(const networking::Connection &con) {
    auto user = connectedUsers.find(con.id);
    activeUsernames.erase(user->second.getUsername());
    user->second.reset();
    sendMessage(con, std::string(AUTH_CONSTANTS::LOGOUT));
    sendMessage(con, std::string(AUTH_CONSTANTS::LOGIN_PROMPT));
}

bool UserManager::registerUser(const networking::Connection& con, const std::string& userInfo) {
    const std::string REGISTER_REGEX = "!REGISTER [a-zA-Z0-9!@#$%^&*()_+=-]+ [[a-zA-Z0-9!@#$%^&*()_+=-]+";

    if (!(std::regex_match(userInfo, std::regex(REGISTER_REGEX)))) {
        sendMessage(con, AUTH_CONSTANTS::MALFORMED);
        return false;
    } else {
        auto userCredentials = parseCredentials(userInfo);
        auto registerResult = rManager->registerUser(userCredentials[1], userCredentials[2]);
        if(registerResult.second) {
            auto user = connectedUsers.find(con.id);
            user->second.setAuthenticated(registerResult.second);
            user->second.setUsername(userCredentials[1]);

            activeUsernames.insert({userCredentials[1], con});
        }
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
    if(user != connectedUsers.end()) {
        user->second.sendMessage(message);
    }
}

void UserManager::sendMessageQueue(const std::deque<std::pair<uintptr_t, std::string>> &messageQueue) {
    for(auto message : messageQueue){
        networking::Connection con = {message.first};
        sendMessage(con, message.second);
    }
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

void UserManager::setHasActiveAvatar(const networking::Connection &con, bool b) {
    auto user = connectedUsers.find(con.id);
    if(user != connectedUsers.end()){
        user->second.setHasActiveAvatar(b);
    }
}

bool UserManager::ifHasActiveAvatar(const networking::Connection &con) {
    auto user = connectedUsers.find(con.id);
    if(user != connectedUsers.end()){
        return user->second.getHasActiveAvatar();
    }
    return -1;
}

void UserManager::addNewCharacter(const networking::Connection &con, std::pair<std::string, int> characterNameAndId) {
    auto user = connectedUsers.find(con.id);
    if(user != connectedUsers.end()){
        user->second.addNewCharacter(characterNameAndId);
    }
}

int UserManager::getOwnedCharacterId(const networking::Connection &con, const std::string& characterName){
    auto user = connectedUsers.find(con.id);
    if(user != connectedUsers.end()){
        return user->second.getOwnedCharacterId(characterName);
    }
    return -1;
}

std::string UserManager::getOwnedCharacterInfo(const networking::Connection &con){
    auto user = connectedUsers.find(con.id);
    return user->second.getOwnedCharacterInfo();

}

void UserManager::printAllUsers() {
    std::cout << "Connected Users: " << std::endl;
    for (auto user : connectedUsers)
        std::cout << user.second.getConnection().id
        << " username:"
        << user.second.getUsername()
        << " authenticated:" << user.second.isAuthenticated()
        << std::endl;
}
