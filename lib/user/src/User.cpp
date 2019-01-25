//
// Created by Dev on 2019-01-17.
//

#include "../include/User.h"

User::User(networking::Connection connection)
        : Username(""),
          Password(""),
          CurrentConnection(connection),
          Authenticated(false),
          Role(User::Unknown)
{
    std::cout << "New user has been created" << std::endl;
};

User::~User(){
    //std::cout << "User has been destroyed" << std::endl;
}

//Getters
const std::string& User::getUsername() const {
    return this->Username;
}

const std::string& User::getPassword() const {
    return this->Password;
}

const networking::Connection& User::getConnection() {
    return this->CurrentConnection;
}

bool User::isAuthenticated(){
    return this->Authenticated;
}

//Setters
void User::setUsername(const std::string &username) {
    this->Username = username;
}

void User::setPassword(const std::string &password) {
    this->Password = password;
}

void User::setAuthenticated(bool b) {
    this->Authenticated = b;
}
