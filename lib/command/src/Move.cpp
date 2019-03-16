#include "Move.h"

namespace commands {
    Move::Move(const networking::Connection connection,
                             const std::string &commandWord,
                             const std::string &enteredCommand) : Command(connection, commandWord, enteredCommand)
                             {}

    Move::~Move(){}

    std::deque<std::pair<uintptr_t , std::string>> Move::process(std::unique_ptr<World>& world) {
        std::deque<std::pair<uintptr_t, std::string>> resultMessages;

        std::cout << "calling " + commandWord;

        return resultMessages;
    }
}