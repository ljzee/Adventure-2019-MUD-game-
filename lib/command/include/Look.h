
#pragma once
#include "Command.h"

namespace commands {
    class Look : public Command {
    public:
        static const std::vector<std::string> values;
        Look(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~Look();

        std::deque<std::pair<uintptr_t , std::string>> process(std::unique_ptr<World>& world) override;
    };
}