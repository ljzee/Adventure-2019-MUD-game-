//
// Created by Vsevolod on 2019-02-08.
//


#include "RegistrationManager.h"
#include <regex>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include <vector>


std::pair<std::string, bool> RegistrationManager::registerUser(const std::string& username, const std::string& pwd) {
    std::ostringstream os;
    bool ifRegistered = false;
    LoginState registrationStatus = validateCredentials(username, "");

    if(registrationStatus == LoginState::WRONG_LOGIN) {
        // login is free, we can use it to register
        //TODO: hash the password and store password
        //TODO: call JsonParser to update user credentials file
        allCredentials.insert(std::make_pair(username, pwd));
        ifRegistered = true;
        os << "You've successfully registered and logged in.";
    } else if(registrationStatus == LoginState::WRONG_PASSWORD) {
        os << "This username is already being used. Please, choose a different one.";
    } else {
        os << "Malformed register call message. Please type !REGISTER <username> <password>.";
    }
    return std::make_pair(os.str(), ifRegistered);
}

std::pair<std::string, bool> RegistrationManager::validateUser(const std::string &username, const std::string &pwd) {
    std::ostringstream os;
    bool ifValidated = false;
    LoginState validationState = validateCredentials(username, pwd);

    switch (validationState) {
        case (LoginState::WRONG_LOGIN):
            os << "Username or password is incorrect. Please try again.";
            break;
        case (LoginState::WRONG_PASSWORD):
            os << "Username or password is incorrect. Please try again.";
            break;
        case (LoginState::CORRECT_PASSWORD):
            os << "You've successfully logged in.";
            ifValidated = true;
        default:
            break;
    }
    return std::make_pair(os.str(), ifValidated);
}

LoginState RegistrationManager::validateCredentials(const std::string &username, const std::string &pwd) {
    auto credentials = allCredentials.find(username);
    LoginState ifRegistered = LoginState::WRONG_LOGIN;

    if(credentials != allCredentials.end()) {
        if(credentials->second == pwd) {
            ifRegistered = LoginState::CORRECT_PASSWORD;
        } else {
            ifRegistered = LoginState::WRONG_PASSWORD;
        }
    }

    return ifRegistered;
}


void RegistrationManager::printAllUsers() {
    std::cout << "Connected connectedUsers: " << std::endl;
    for (auto const& user : allCredentials)
        std::cout << user.first
                  << " username:"
                  << user.second
                  << " password:"
                  << std::endl;
}
