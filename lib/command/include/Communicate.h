
#pragma once
#include "Command.h"
#include "utils.h"

namespace commands {
    STRING_ENUM(CommCommands, SAY, YELL, TELL);
    class Communicate : public Command {
    public:
        Communicate(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~Communicate();

            std::deque<std::pair<uintptr_t , std::string>> process(std::unique_ptr<World>& world) override;
    private:

    };
}
