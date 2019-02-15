//
// Created by Dev on 2019-02-11.
//

#ifndef PROJECT_COMMANDSAY_H
#define PROJECT_COMMANDSAY_H

#include "command.h"
#include "Server.h"


namespace commands {

    class CommandNotExist : public Command {
    public:
        CommandNotExist(const networking::Connection &caller, const std::string &enteredCommand);

        ~CommandNotExist();

        std::deque<std::pair<int, std::string>> process(World &world);


    };

    class CommandSay : public Command {
    public:
        CommandSay(const networking::Connection &caller, const std::string &enteredCommand);

        ~CommandSay();

        std::deque<std::pair<int, std::string>> process(World &world);


    };

}

#endif //PROJECT_COMMANDSAY_H
