//
// Created by Dev on 2019-02-09.
//

#ifndef ADVENTURE2019_COMMAND_H
#define ADVENTURE2019_COMMAND_H

#include <deque>

#include <string>
#include <sstream>
#include <iostream>
#include "boost/assign/list_of.hpp"
#include "world.h"
#include "Server.h"
#include "string_enum.h"

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

    networking::Connection getCallerConnection();
    virtual std::deque<std::pair<uintptr_t, std::string>> process(std::unique_ptr<World>& world) = 0;
};


#endif //ADVENTURE2019_COMMAND_H
