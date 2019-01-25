//
// Created by Dev on 2019-01-17.
//

#ifndef USER_H
#define USER_H

#include <iostream>
#include <boost/algorithm/string.hpp>
#include "Server.h"

/**
 * User Class:
 *
 * - maintains a single connections
 * - owns an instance of avatar class (once User authenticates, avatar object is placed into the world)
 * - holds state information of avatar(current room) for quick command proccessing
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

    ~User();

    //Getters
    const std::string& getUsername() const;

    const std::string& getPassword() const;

    const networking::Connection& getConnection();

    bool isAuthenticated();

    //Setters
    void setUsername(const std::string& username);

    void setPassword(const std::string& password);

    void setAuthenticated(bool b);


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