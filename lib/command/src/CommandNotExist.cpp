#include "CommandNotExist.h"

namespace commands {
    CommandNotExist::CommandNotExist(const networking::Connection connection,
                                     const std::string &commandWord,
                                     const std::string &enteredCommand): Command(connection, commandWord, enteredCommand)
                                     {}

    CommandNotExist::~CommandNotExist() {}

    std::deque<std::pair<uintptr_t , std::string>> CommandNotExist::process(std::unique_ptr<World>& world) {
        std::deque<std::pair<uintptr_t, std::string>> resultMessages;
        std::cout << std::string("No such command: ") + this->commandWord << std::endl;
        return resultMessages;
    }
}