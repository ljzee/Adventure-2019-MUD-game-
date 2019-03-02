//
// Created by Dev on 2019-02-11.
//

#ifndef PROJECT_COMMANDSAY_H
#define PROJECT_COMMANDSAY_H

#include "command.h"
#include "Server.h"

/**
 *
 * Contains the declaration of all command subclasses
 *
 */

namespace commands {

    ///Handles when command doesn't exist
    class CommandNotExist : public Command {
    public:
        CommandNotExist(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~CommandNotExist();

        std::deque<std::pair<uintptr_t , std::string>> process(World &world);

    };

    ///Handles say, tell, yell
    class CommandCommunicate : public Command {
    public:
        CommandCommunicate(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~CommandCommunicate();

        std::deque<std::pair<uintptr_t , std::string>> process(World &world);

    };

    ///Handles north, south, east, west
    class CommandMove : public Command {
    public:
        CommandMove(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~CommandMove();

        std::deque<std::pair<uintptr_t , std::string>> process(World &world);
    };

    ///Handles look, examine
    class CommandLook : public Command {
    public:
        CommandLook(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~CommandLook();

        std::deque<std::pair<uintptr_t , std::string>> process(World &world);
    };

    ///Handles get, put, drop, give, wear, remove
    class CommandItem : public Command {
    public:
        CommandItem(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~CommandItem();

        std::deque<std::pair<uintptr_t , std::string>> process(World &world);
    };

    ///Handles attack, kill
    class CommandCombat : public Command {
    public:
        CommandCombat(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~CommandCombat();

        std::deque<std::pair<uintptr_t , std::string>> process(World &world);
    };

    ///Handles swap
    class CommandSwap : public Command {
    public:
        CommandSwap(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~CommandSwap();

        std::deque<std::pair<uintptr_t , std::string>> process(World &world);
    };

}

#endif //PROJECT_COMMANDSAY_H