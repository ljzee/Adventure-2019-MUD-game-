//
// Created by Dev on 2019-01-24.
//

#include "../include/UserManager.h"
#include <regex>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include <vector>

using namespace boost;


//adds a new user
void UserManager::addUser(User &newUser) {
    connectedUsers.insert({newUser.getConnection().id, newUser});
}

//remove a current user, on logout or disconnect
void UserManager::removeUser(const networking::Connection& con) {
    connectedUsers.erase(con.id);
}

std::vector<std::string> UserManager::parseCredentials(const std::string& userInfo) {
    std::vector<std::string> credentials;
    auto login_pattern = std::regex(UserManager::LOGIN_REGEX);

    boost::split(credentials, userInfo, boost::is_any_of(" "));
    return credentials;
}

void UserManager::registerUser(const networking::Connection& con, const std::string& userInfo) {
    std::vector<std::string> credentials = parseCredentials(userInfo);
    std::ostringstream os;
    if(credentials.size() == 2) {
        std::pair<std::string, LoginState> registrationStatus = checkRegistration(credentials[0], " ");
        if(registrationStatus.second == LoginState::WRONG_LOGIN) {
            //TODO: hash the password and store password
            //TODO: call JsonParser to update user credentials file
            std::cout << credentials[0] << credentials[1] << std::endl;
            registeredUsers.insert(std::make_pair(credentials[0], credentials[1]));
            os << "You've succesfully registered. Now you can login using your credentials.";
        } else if(registrationStatus.second == LoginState::WRONG_PASSWORD) {
            os << "This username is already being used. Please, choose a different one.";
        }
    } else {
        os << "Malformed register call message. Please type !REGISTER <username> <password>.";
    }
    sendMessage(con, os.str());
}

//authenticate a user when user sends "!LOGIN <username> <password>
void UserManager::authenticate(const networking::Connection &con, const std::string &userInfo) {
    auto user = connectedUsers.find(con.id);
    std::ostringstream os;

    std::vector<std::string> credentials = parseCredentials(userInfo);
    if(credentials.size() == 2) {
        std::cout << credentials[0] << credentials[1] << std::endl;
        std::pair<std::string, LoginState > registrationStatus = checkRegistration(credentials[0], credentials[1]);
        os << registrationStatus.first;
        user->second.setAuthenticated(LoginState::CORRECT_PASSWORD == registrationStatus.second);
    } else {
        os << "Malformed authenticate call message. Please type !LOGIN <username> <password>";
    }
    user->second.sendMessage(os.str());
}

//check if a particular connection is authenticated
bool UserManager::isAuthenticated(const networking::Connection& con) {
    auto user = connectedUsers.find(con.id);
    if (user != connectedUsers.end()) {
        return user->second.isAuthenticated();
    }
    return false; //will also return false if connection does not exist in UserManager
}

std::pair<std::string, LoginState> UserManager::checkRegistration(const std::string &username, const std::string &pwd) {
    auto credentials = registeredUsers.find(username);
    std::ostringstream os;
    LoginState ifRegistered = LoginState::WRONG_LOGIN;

    if(credentials != registeredUsers.end()) {
        if(credentials->second == pwd) {
            os << "You are logged in now!" << std::endl;
            ifRegistered = LoginState::CORRECT_PASSWORD;
        } else {
            os << "Your password is wrong. Try again." << std::endl;
            ifRegistered = LoginState::WRONG_PASSWORD;
        }
    } else {
        os << "No such user found. Please, register first!" << std::endl;
    }
    return std::make_pair(os.str(), ifRegistered);

}

//logout an authenticated user
void UserManager::logout(const networking::Connection &con) {
    auto user = connectedUsers.find(con.id);
    if(user != connectedUsers.end()){
        user->second.setAuthenticated(false);
        user->second.setUsername("");
        user->second.setPassword("");
    }
}

//send message to a particular user
void UserManager::sendMessage(const networking::Connection& con, const std::string& message) {
    auto user = connectedUsers.find(con.id);
    if(user != connectedUsers.end()) {
        user->second.sendMessage(message);
    }
}

//build a deque of all messages to be sent to each user
std::deque<networking::Message> UserManager::buildOutgoing() {
    std::deque<networking::Message> outgoing;
    for (auto user=connectedUsers.begin(); user != connectedUsers.end(); user++) {
        if(!user->second.isMessageEmpty()){
            outgoing.push_back({user->second.getConnection(), user->second.getUserMessagesConcatenated()});
            user->second.clearMessages();
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
        << " password:"
        << user.second.getPassword()
        << " authenticated:" << user.second.isAuthenticated()
        << std::endl;
}
