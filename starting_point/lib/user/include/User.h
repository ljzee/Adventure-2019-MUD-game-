//
// Created by Dev on 2019-01-17.
//

#ifndef USER_H
#define USER_H

#include <iostream>
#include <boost/algorithm/string.hpp>
#include "Server.h"

/**
 *
 * A class to contain authentication information for an incoming connection.
 * To be used server side to keep track of connection authentication.
 *
 *
 */

class User {

public:
    enum Roles
    {
        Unknown = 0,
        Casual,
        WorldBuilder
    };

    User(networking::Connection connection);

    User(std::string username, std::string password, networking::Connection connection);

    ~User();

    bool isAuthenticated();

    void setAuthenticated();

    networking::Connection getConnection();

    bool operator==(networking::Connection other) const {
        return CurrentConnection.id == other.id;
    }

private:

    std::string Username;
    std::string Password;
    networking::Connection CurrentConnection;
    bool Authenticated;
    Roles Role;

};

#endif //ADVENTURE2019_USER_H