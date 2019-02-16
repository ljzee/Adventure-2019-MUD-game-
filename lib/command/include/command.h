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
 * - base Command class, should not be instantiated
 * - subclass for each command(related actions) to override processing behaviour
 *
 */

struct Command {

    enum Roles
    {
        Casual = 0,
        WorldBuilder
    };

    //Command Specification

    Roles role;                     //what role can call this command
    bool minigameCallable;          //can this command be callable within minigame
    int minimumArguments;           //minimum number of arguments to call a command
    std::string commandFormat;      //helper string for when minimum arguments not met

    //Execution arguments

    //replace int with avatarID type if available
    int caller;                     //avatarId that the object relates to
    std::string enteredCommand;     //command string that user entered and to be parsed



    Command(Command::Roles, bool minigameCallable, int minimumArguments, const std::string& commandFormat, int caller, const std::string& enteredCommand);

    virtual ~Command() = 0;

    //Override process in subclass to have its own processing behaviour
    //if int is still present, replace with ID type if available
    virtual std::deque<std::pair<int, std::string>> process(World &world) = 0;

    //Testing
    //void print();

};


#endif //ADVENTURE2019_COMMAND_H
