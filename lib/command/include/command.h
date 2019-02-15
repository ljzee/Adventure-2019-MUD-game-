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


struct Command {

    enum Roles
    {
        Casual = 0,
        WorldBuilder
    };

    std::string commandName;
    Roles role;
    bool minigameCallable;
    int minimumArguments;
    std::string commandFormat;

    Command(const std::string& commandName, Command::Roles, bool minigameCallable, int minimumArguments, const std::string& commandFormat);

    virtual ~Command() = 0;

    //Override processCommand in subclass to have its own processing behaviour
    //if int is still present, replace with ID type if available
    virtual std::deque<std::pair<int, std::string>> process(int avatarId, std::string &command, World &world) = 0;

};


#endif //ADVENTURE2019_COMMAND_H
