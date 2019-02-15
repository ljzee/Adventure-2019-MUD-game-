//
// Created by Dev on 2019-02-11.
//

#include "commandDeclaration.h"

namespace commands {

    CommandNotExist::CommandNotExist(const networking::Connection &caller,
               const std::string &enteredCommand) : Command(Command::Casual, true, 2, "say [message]",
                                                            caller, enteredCommand) {}

    CommandNotExist::~CommandNotExist() {}

    std::deque<std::pair<int, std::string>> CommandNotExist::process(World &world) {
        std::deque<std::pair<int, std::string>> resultMessages;
        auto commandWord = enteredCommand.substr(0, enteredCommand.find(' '));
        std::cout << std::string("No such command: ") + commandWord << std::endl;
        return resultMessages;
    }



    CommandSay::CommandSay(const networking::Connection &caller,
                           const std::string &enteredCommand) : Command(Command::Casual, true, 2, "say [message]",
                                                                        caller, enteredCommand) {}

    CommandSay::~CommandSay() {}

    std::deque<std::pair<int, std::string>> CommandSay::process(World &world) {
        std::deque<std::pair<int, std::string>> resultMessages;
        std::cout << "calling say" << std::endl;
        return resultMessages;
    }

}