 
#pragma once
#include "Command.h"

namespace commands {
    STRING_ENUM(ItemCommands, GET, PUT, DROP, GIVE, WEAR, REMOVE);
    class CommandItem : public Command {
    public:
        CommandItem(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~CommandItem();

        std::deque<std::pair<uintptr_t , std::string>> process(std::unique_ptr<World>& world) override;
    };
}
