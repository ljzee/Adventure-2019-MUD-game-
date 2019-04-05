
#pragma once
#include "Command.h"

namespace commands {
    class Communicate : public Command {
    public:
        static const std::vector<std::string> values;
        Communicate(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

        ~Communicate();

            std::deque<std::pair<uintptr_t , std::string>> process(std::unique_ptr<World>& world) override;
    private:

    };
}
