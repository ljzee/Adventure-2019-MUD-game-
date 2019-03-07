#include "Move.h"

namespace commands {
    std::vector<std::string> const Move::values = boost::assign::list_of("north")("south")("east")("west");
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