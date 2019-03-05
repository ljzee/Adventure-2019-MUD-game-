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

    std::deque<std::pair<uintptr_t , std::string>> CommandNotExist::process(std::unique_ptr<World>& world) {
        std::deque<std::pair<uintptr_t, std::string>> resultMessages;
        std::cout << std::string("No such command: ") + this->commandWord << std::endl;
        return resultMessages;
    }

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

    ///Handles north, south, east, west
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

    ///Handles look, examine
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

    ///Handles get, put, drop, give
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

    ///Handles attack, kill
    CommandCombat::CommandCombat(const networking::Connection connection,
                                 const std::string &commandWord,
                                 const std::string &enteredCommand): Command(connection, commandWord, enteredCommand)
                                 {}

    CommandCombat::~CommandCombat(){}

    std::deque<std::pair<uintptr_t , std::string>> CommandCombat::process(std::unique_ptr<World>& world) {
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

    std::deque<std::pair<uintptr_t , std::string>> CommandSwap::process(std::unique_ptr<World>& world) {
        std::deque<std::pair<uintptr_t, std::string>> resultMessages;

        if(this->commandWord == "swap"){
            std::cout << "calling swap" << std::endl;
            return resultMessages;
        }

        return resultMessages;
    }

}