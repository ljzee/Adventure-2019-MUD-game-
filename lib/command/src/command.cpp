//
// Created by Dev on 2019-02-09.
//

#include "command.h"

Command::Command(Command::Roles roleRequired,
                 bool minigameCallable,
                 int minimumArguments,
                 const std::string &commandFormat,
                 const networking::Connection &caller,
                 const std::string &enteredCommand) : role(roleRequired),
                                                      minigameCallable(minigameCallable),
                                                      minimumArguments(minimumArguments),
                                                      commandFormat(commandFormat),
                                                      caller(caller),
                                                      enteredCommand(enteredCommand)
                                                      {}

Command::~Command() {}