//
// Created by Vsevolod on 2019-02-08.
//

#ifndef ADVENTURE_REGISTEREDUSERMANAGER_H
#define ADVENTURE_REGISTEREDUSERMANAGER_H


#include <unordered_map>
#include "User.h"
#include <iostream>
#include <deque>
#include "Server.h"
#include <vector>
#include "../../mud/include/JSONParser.h"

enum LoginState {
    CORRECT_LOGIN,
    CORRECT_PASSWORD,
    WRONG_LOGIN,
    WRONG_PASSWORD
};


class RegistrationManager {
public:



    std::pair<std::string, bool> registerUser(const std::string& username, const std::string& pwd);

    // will be called outside to validate credentials
    std::pair<std::string, bool> validateUser(const std::string& username, const std::string &pwd);


    void printAllUsers(); //For Testing

private:
    // will be called inside to assist validateCredentials function
    LoginState validateCredentials(const std::string &username, const std::string &pwd);

    // map to store all registered users' credentials
    std::unordered_map<std::string, std::string> allCredentials;

};


#endif //ADVENTURE_REGISTEREDUSERMANAGER_H
