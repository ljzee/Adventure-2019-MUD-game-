//
// Created by Dev on 2019-01-17.
//

#include "../include/User.h"



User(string username, string password, Roles role)
    : Username(username),
      Password(password),
      Role(role)
{
    std::cout << "New user has been created" << endl;
};
