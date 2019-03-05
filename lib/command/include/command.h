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
protected:
    std::string commandWord;
    std::string enteredCommand;
    networking::Connection callerConnection;
public:
    Command(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);
    virtual ~Command() = 0;

    uintptr_t getCallerConnectionId();
    virtual std::deque<std::pair<uintptr_t, std::string>> process(std::unique_ptr<World>& world) = 0;
};


#endif //ADVENTURE2019_COMMAND_H
