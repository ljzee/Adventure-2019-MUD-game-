//
// Created by Dev on 2019-02-09.
//

#ifndef ADVENTURE2019_COMMAND_H
#define ADVENTURE2019_COMMAND_H

#include <deque>
#include "world.h"

#include <string>
#include <sstream>
#include <iostream>
#include "Server.h"

/**
 * Command Class:
 *
 * - base Command class
 * - //
 *
 */

class Command {
private:
    std::string commandWord;
    std::string enteredCommand;
    int caller;
    networking::Connection callerConnectionID;
public:
    Command(const networking::Connection connectionID, int callerID, std::string enteredCommand);
    ~Command();

    int getCaller();
    networking::Connection getConnectionID();

    std::deque<std::pair<int, std::string>> process(World &world);
};


#endif //ADVENTURE2019_COMMAND_H
