//
// Created by Dev on 2019-01-17.
//

#ifndef USER_H
#define USER_H

#include <iostream>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include "Server.h"
#include <deque>

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

    ///Constructor
    User(networking::Connection connection);

    ///Destructor
    ~User();

    ///Getters
    const std::string& getUsername() const;

    const std::string& getPassword() const;

    const networking::Connection& getConnection();

    bool isAuthenticated();

    ///Setters
    void setUsername(const std::string& username);

    void setPassword(const std::string& password);

    void setAuthenticated(bool b);

    ///User Message Container Operations
    //deposits a message in the User's message container
    void sendMessage(std::string& message);

    //returns a concatenated string of all of User's messages
    std::string getUserMessagesConcatenated();

    //clears User's message container
    void clearMessages();

    //check if message container is empty
    bool isMessageEmpty();

    ///Utility
    void printUserMemberValues();

    bool operator==(networking::Connection other) const {
        return currentConnection.id == other.id;
    }


private:

    std::string username;
    std::string password;
    networking::Connection currentConnection;
    bool authenticated;
    Roles role;

    std::deque<std::string> userMessageDeque;

};

#endif //ADVENTURE2019_USER_H