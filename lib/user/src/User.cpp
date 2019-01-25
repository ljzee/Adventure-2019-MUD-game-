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

User::User(std::string username, std::string password, networking::Connection connection)
        : Username(username),
          Password(password),
          CurrentConnection(connection),
          Authenticated(false),
          Role(User::Unknown)
{
    std::cout << "New user has been created" << std::endl;
};

User::~User(){
    //std::cout << "User has been destroyed" << std::endl;
}

bool User::isAuthenticated(){
    return this->Authenticated;
}

void User::setAuthenticated() {
    this->Authenticated = true;
}


networking::Connection User::getConnection() {
    return this->CurrentConnection;
}