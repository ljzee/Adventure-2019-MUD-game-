//
// Created by Dev on 2019-02-09.
//

#include "command.h"

Command::Command(const std::string &commandName,
                 Command::Roles,
                 bool minigameCallable,
                 int minimumArguments,
                 const std::string &commandFormat) : commandName(commandName),
                                                     role(Roles::Casual),
                                                     minigameCallable(minigameCallable),
                                                     minimumArguments(minimumArguments),
                                                     commandFormat(commandFormat)
                                                     {}

 Command::~Command() {

}