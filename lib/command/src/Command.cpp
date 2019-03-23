//
// Created by Dev on 2019-02-09.
//

#include "Command.h"


Command::Command(const networking::Connection connection,
                 const std::string &commandWord,
                 const std::string &enteredCommand) : commandWord(commandWord),
                                                      enteredCommand(enteredCommand),
                                                      callerConnection(connection)

                 {}

Command::~Command(){
    
}

networking::Connection Command::getCallerConnection() {
    return this->callerConnection;
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