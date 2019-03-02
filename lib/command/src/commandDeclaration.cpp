//
// Created by Dev on 2019-02-11.
//

#include "commandDeclaration.h"

namespace commands {

    ///Handles when command doesn't exist
    CommandNotExist::CommandNotExist(const networking::Connection connection,
                                     const std::string &commandWord,
                                     const std::string &enteredCommand): Command(connection, commandWord, enteredCommand)
                                     {}

    CommandNotExist::~CommandNotExist() {}

    std::deque<std::pair<uintptr_t , std::string>> CommandNotExist::process(World &world) {
        std::deque<std::pair<uintptr_t, std::string>> resultMessages;
        std::cout << std::string("No such command: ") + this->commandWord << std::endl;
        return resultMessages;
    }

    ///Handles say, tell, yell
    CommandCommunicate::CommandCommunicate(const networking::Connection connection,
                                           const std::string &commandWord,
                                           const std::string &enteredCommand): Command(connection, commandWord, enteredCommand)
                                           {}

    CommandCommunicate::~CommandCommunicate() {}

    std::deque<std::pair<uintptr_t, std::string>> CommandCommunicate::process(World &world) {
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

    ///Handles north, south, east, west
    CommandMove::CommandMove(const networking::Connection connection,
                             const std::string &commandWord,
                             const std::string &enteredCommand) : Command(connection, commandWord, enteredCommand)
                             {}

    CommandMove::~CommandMove(){}

    std::deque<std::pair<uintptr_t , std::string>> CommandMove::process(World &world) {
        std::deque<std::pair<uintptr_t, std::string>> resultMessages;

        std::cout << "calling " + commandWord;

        return resultMessages;
    }

    ///Handles look, examine
    CommandLook::CommandLook(const networking::Connection connection,
                             const std::string &commandWord,
                             const std::string &enteredCommand): Command(connection, commandWord, enteredCommand)
                             {}

    CommandLook::~CommandLook() {}

    std::deque<std::pair<uintptr_t , std::string>> CommandLook::process(World &world) {
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

    ///Handles get, put, drop, give
    CommandItem::CommandItem(const networking::Connection connection,
                             const std::string &commandWord,
                             const std::string &enteredCommand): Command(connection, commandWord, enteredCommand)
                             {}

    CommandItem::~CommandItem(){}

    std::deque<std::pair<uintptr_t , std::string>> CommandItem::process(World &world) {
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

    ///Handles attack, kill
    CommandCombat::CommandCombat(const networking::Connection connection,
                                 const std::string &commandWord,
                                 const std::string &enteredCommand): Command(connection, commandWord, enteredCommand)
                                 {}

    CommandCombat::~CommandCombat(){}

    std::deque<std::pair<uintptr_t , std::string>> CommandCombat::process(World &world) {
        std::deque<std::pair<uintptr_t, std::string>> resultMessages;

        if(this->commandWord == "attack"){
            std::cout << "calling attack" << std::endl;
            return resultMessages;
        }

        if(this->commandWord == "kill"){
            std::cout << "calling kill" << std::endl;
            return resultMessages;
        }

        return resultMessages;
    }

    ///Handles swap
    CommandSwap::CommandSwap(const networking::Connection connection,
                                 const std::string &commandWord,
                                 const std::string &enteredCommand): Command(connection, commandWord, enteredCommand)
                                 {}

    CommandSwap::~CommandSwap(){}

    std::deque<std::pair<uintptr_t , std::string>> CommandSwap::process(World &world) {
        std::deque<std::pair<uintptr_t, std::string>> resultMessages;

        if(this->commandWord == "swap"){
            std::cout << "calling swap" << std::endl;
            return resultMessages;
        }

        return resultMessages;
    }

}