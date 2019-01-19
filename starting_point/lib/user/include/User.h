//
// Created by Dev on 2019-01-17.
//

#ifndef USER_H
#define USER_H

#include <iostream>
#include <boost/algorithm/string.hpp>
#include "Server.h"

class User {

public:
    enum Roles
    {
        Unknown = 0,
        Casual,
        WorldBuilder
    };

    User(std::string username, std::string password, networking::Connection connection);

    bool isAuthenticated();

private:

    std::string Username;
    std::string Password;
    networking::Connection CurrentConnection;
    bool Authenticated;
    Roles Role;

};


#endif //ADVENTURE2019_USER_H
