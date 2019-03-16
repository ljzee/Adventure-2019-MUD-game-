#include "Communicate.h"

namespace commands {
     ///Handles say, tell, yell
        Communicate::Communicate(const networking::Connection connection,
                                           const std::string &commandWord,
                                           const std::string &enteredCommand): Command(connection, commandWord, enteredCommand)
                                           {}

    Communicate::~Communicate() {}

    std::deque<std::pair<uintptr_t, std::string>> Communicate::process(std::unique_ptr<World>& world) {
        std::deque<std::pair<uintptr_t, std::string>> resultMessages;

        if(this->commandWord == "say") {
            std::cout << "calling say" << std::endl;
            return resultMessages;
        }

        if(this->commandWord == "tell") {
            std::cout << "calling tell" << std::endl;
            return resultMessages;
        }

        if(this->commandWord == "yell") {
            std::cout << "calling yell" << std::endl;
            return resultMessages;
        }

        return resultMessages;
    }
}