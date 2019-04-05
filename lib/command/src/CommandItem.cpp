#include "CommandItem.h"

namespace commands {
    CommandItem::CommandItem(const networking::Connection connection,
                             const std::string &commandWord,
                             const std::string &enteredCommand): Command(connection, commandWord, enteredCommand)
                             {}

    CommandItem::~CommandItem(){}

    std::deque<std::pair<uintptr_t , std::string>> CommandItem::process(std::unique_ptr<World>& world) {
        std::deque<std::pair<uintptr_t, std::string>> resultMessages;

        if(this->commandWord == "get"){
            std::cout << "calling get" << std::endl;
            return resultMessages;
        }

        if(this->commandWord == "put"){
            std::cout << "calling put" << std::endl;
            return resultMessages;
        }

        if(this->commandWord == "drop"){
            std::cout << "calling drop" << std::endl;
            return resultMessages;
        }

        if(this->commandWord == "give"){
            std::cout << "calling give" << std::endl;
            return resultMessages;
        }

        if(this->commandWord == "wear"){
            std::cout << "calling wear" << std::endl;
            return resultMessages;
        }

        if(this->commandWord == "remove"){
            std::cout << "calling remove" << std::endl;
            return resultMessages;
        }

        return resultMessages;
    }
}