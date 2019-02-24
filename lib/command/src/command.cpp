//
// Created by Dev on 2019-02-09.
//

#include "command.h"

Command::Command(const networking::Connection connectionID, int callerID, std::string enteredCommand) {
    //split string
    this->commandWord = "say"; // change later
    this->enteredCommand = enteredCommand;
    this->caller = callerID;
    this->callerConnectionID = connectionID;
}

Command::~Command() {
    cout << "destructing command object";
}

int Command::getCaller() {
    return this->caller;
}
networking::Connection Command::getConnectionID() {
    return this->callerConnectionID;
}

std::deque<std::pair<int, std::string>> Command::process(World &world) {
    std::deque<std::pair<int, std::string>> resultMessages;
    std::cout << "calling say" << std::endl; //terminal update
    // add pairs to resultMessages
    return resultMessages; // empty deque
}