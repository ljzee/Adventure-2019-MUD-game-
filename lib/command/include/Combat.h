
#pragma once
#include "Command.h"

namespace commands {

STRING_ENUM(CombatCommands, ATTACK, KILL);

class CommandCombat : public Command {
    public:
        
        CommandCombat(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~CommandCombat();

        std::deque<std::pair<uintptr_t , std::string>> process(std::unique_ptr<World>& world) override;
    };
}