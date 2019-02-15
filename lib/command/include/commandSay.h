//
// Created by Dev on 2019-02-11.
//

#ifndef PROJECT_COMMANDSAY_H
#define PROJECT_COMMANDSAY_H

#include "command.h"

class CommandSay : public Command{
public:
    CommandSay(const std::string &commandName, Command::Roles, bool minigameCallable, int minimumArguments, const std::string &commandFormat);

    ~CommandSay();

    std::deque<std::pair<int, std::string>> process(int avatarId, std::string &command, World &world);


};


#endif //PROJECT_COMMANDSAY_H
