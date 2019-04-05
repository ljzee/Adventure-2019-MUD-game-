#include "Swap.h"

namespace commands {
     ///Handles swap
    CommandSwap::CommandSwap(const networking::Connection connection,
                                 const std::string &commandWord,
                                 const std::string &enteredCommand): Command(connection, commandWord, enteredCommand)
                                 {}

    CommandSwap::~CommandSwap(){}

    std::deque<std::pair<uintptr_t , std::string>> CommandSwap::process(std::unique_ptr<World>& world) {
        std::deque<std::pair<uintptr_t, std::string>> resultMessages;

        if(this->commandWord == "swap"){
            std::cout << "calling swap" << std::endl;
            return resultMessages;
        }
        
        return resultMessages;
    }
}