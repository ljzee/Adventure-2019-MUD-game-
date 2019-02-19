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

    ///Constructor
    User(networking::Connection connection);
    User(std::string username);

    ///Destructor
    ~User();

    ///Getters
    const std::string& getUsername() const;

    const networking::Connection& getConnection() const;

    bool isAuthenticated();

    int getActiveAvatarId();

    ///Setters
    void setUsername(const std::string& username);

    void setAuthenticated(bool b);

    void setActiveAvatarId(int id);

    //resets member fields to null state, used in logout
    void reset();
    ///User Message Container Operations
    //deposits a message in the User's message container
    void sendMessage (const std::string& message);

    //returns a concatenated string of all of User's messages
    std::string getUserMessagesConcatenated() const;

    //clears User's message container
    void clearMessages();

    //check if message container is empty
    bool isMessageEmpty() const;

    ///Utility
    void printUserMemberValues();

    bool operator==(networking::Connection other) const {
        return currentConnection.id == other.id;
    }


private:

    std::string username;
    networking::Connection currentConnection;
    bool authenticated;
    std::deque<std::string> userMessageDeque;
    int activeAvatarId;
};

#endif //ADVENTURE2019_USER_H