#include "Look.h"

namespace commands {
    std::vector<std::string> const Look::values = boost::assign::list_of("look")("examine");
    Look::Look(const networking::Connection connection,
                             const std::string &commandWord,
                             const std::string &enteredCommand): Command(connection, commandWord, enteredCommand)
                             {}

    Look::~Look() {}

    std::deque<std::pair<uintptr_t , std::string>> Look::process(std::unique_ptr<World>& world) {
        std::deque<std::pair<uintptr_t, std::string>> resultMessages;

        if(this->commandWord == "look"){
            std::cout << "calling look" << std::endl;
            return resultMessages;
        }

        if(this->commandWord == "examine"){
            std::cout << "calling examine" << std::endl;
            return resultMessages;
        }

        return resultMessages;
    }
}