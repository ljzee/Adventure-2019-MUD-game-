//
// Created by Dev on 2019-02-09.
//

#include "command.h"


Command::Command(const networking::Connection connection,
                 const std::string &commandWord,
                 const std::string &enteredCommand) : commandWord(commandWord),
                                                      enteredCommand(enteredCommand),
                                                      callerConnection(connection)

                 {}

Command::~Command(){}

uintptr_t Command::getCallerConnectionId() {
    return this->callerConnection.id;
}

//testing
/*
void Command::print() {
    std::cout << role
              << " "
              << minigameCallable
              << " "
              << minimumArguments
              << " "
              << commandFormat
              << " "
              << caller
              << " "
              << enteredCommand
              << std::endl;
}
*/