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


struct Command {

    enum Roles
    {
        Casual = 0,
        WorldBuilder
    };

    //Command Specification
    Roles role;
    bool minigameCallable;
    int minimumArguments;
    std::string commandFormat;

    //Execution arguments
    networking::Connection caller;
    std::string enteredCommand;



    Command(Command::Roles, bool minigameCallable, int minimumArguments, const std::string& commandFormat, const networking::Connection &caller, const std::string& enteredCommand);

    virtual ~Command() = 0;

    //Override processCommand in subclass to have its own processing behaviour
    //if int is still present, replace with ID type if available
    virtual std::deque<std::pair<int, std::string>> process(World &world) = 0;

};


#endif //ADVENTURE2019_COMMAND_H
