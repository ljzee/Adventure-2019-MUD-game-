#pragma once
#include "Command.h"

namespace commands {
    STRING_ENUM(NotExistCommands, NOTEXIST);
    class CommandNotExist : public Command {
    public:
        static const std::vector<std::string> values;
        CommandNotExist(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~CommandNotExist();

        std::deque<std::pair<uintptr_t , std::string>> process(std::unique_ptr<World>& world) override;
    private:
    };
}
