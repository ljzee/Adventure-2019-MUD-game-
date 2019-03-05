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

        std::deque<std::pair<uintptr_t , std::string>> process(std::unique_ptr<World>& world);

    };

    ///Handles say, tell, yell
    class Communicate : public Command {
    public:
        Communicate(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~Communicate();

        std::deque<std::pair<uintptr_t , std::string>> process(std::unique_ptr<World>& world);

    };

    ///Handles north, south, east, west
    class Move : public Command {
    public:
        Move(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~Move();

        std::deque<std::pair<uintptr_t , std::string>> process(std::unique_ptr<World>& world);
    };

    ///Handles look, examine
    class Look : public Command {
    public:
        Look(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~Look();

        std::deque<std::pair<uintptr_t , std::string>> process(std::unique_ptr<World>& world);
    };

    ///Handles get, put, drop, give, wear, remove
    class CommandItem : public Command {
    public:
        CommandItem(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~CommandItem();

        std::deque<std::pair<uintptr_t , std::string>> process(std::unique_ptr<World>& world);
    };

    ///Handles attack, kill
    class CommandCombat : public Command {
    public:
        CommandCombat(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~CommandCombat();

        std::deque<std::pair<uintptr_t , std::string>> process(std::unique_ptr<World>& world);
    };

    ///Handles swap
    class CommandSwap : public Command {
    public:
        CommandSwap(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~CommandSwap();

        std::deque<std::pair<uintptr_t , std::string>> process(std::unique_ptr<World>& world);
    };

}

#endif //PROJECT_COMMANDSAY_H