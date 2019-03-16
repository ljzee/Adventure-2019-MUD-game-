///Handles north, south, east, west
#pragma once
#include "Command.h"

namespace commands {
    STRING_ENUM(MoveCommands, NORTH, SOUTH, EAST, WEST);
    class Move : public Command {
    public:
        Move(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~Move();

        std::deque<std::pair<uintptr_t , std::string>> process(std::unique_ptr<World>& world);
    };
}

