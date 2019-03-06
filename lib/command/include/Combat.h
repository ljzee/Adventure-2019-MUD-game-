
#pragma once
#include "Command.h"

namespace commands {
class CommandCombat : public Command {
    public:
        static const std::vector<std::string> values;
        CommandCombat(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~CommandCombat();

        std::deque<std::pair<uintptr_t , std::string>> process(std::unique_ptr<World>& world) override;
    };
}