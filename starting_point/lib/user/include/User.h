//
// Created by Dev on 2019-01-17.
//

#ifndef USER_H
#define USER_H

#include <iostream>
#include <boost/algorithm/string.hpp>

using namespace boost;

class User {

public:
    enum Roles
    {
        WorldBuilder = 0,
        Casual
    };

    User(string username, string password, Roles role);

private:

    std::string Username;
    std::string Password;
    Roles Role;

};


#endif //ADVENTURE2019_USER_H
