//
// Created by Dev on 2019-02-09.
//

#include "command.h"

Command::Command(int callerID, std::string enteredCommand) {
    //split string
    this->commandWord = "say";
    this->enteredCommand = enteredCommand;
    this->caller = callerID;
}

Command::~Command() {}

int Command::getCaller() {
    return this->caller;
}

std::deque<std::pair<int, std::string>> Command::process(World &world) {
    std::deque<std::pair<int, std::string>> resultMessages;
    std::cout << "calling say" << std::endl;
    // add pairs to resultMessages
    return resultMessages; // empty deque
}