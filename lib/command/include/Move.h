///Handles north, south, east, west
#pragma once
#include "Command.h"

namespace commands {
    class Move : public Command {
    public:
        static const std::vector<std::string> values;
        Move(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~Move();

        std::deque<std::pair<uintptr_t , std::string>> process(std::unique_ptr<World>& world);
    };
}

