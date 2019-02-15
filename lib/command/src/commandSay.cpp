//
// Created by Dev on 2019-02-11.
//

#include "commandSay.h"

CommandSay::CommandSay(const std::string &commandName,
                       Command::Roles,
                       bool minigameCallable,
                       int minimumArguments,
                       const std::string &commandFormat) : Command(commandName, Command::Casual, minigameCallable, minimumArguments, commandFormat)
                       {}

CommandSay::~CommandSay() {}

std::deque<std::pair<int, std::string>> CommandSay::process(int avatarId, std::string &command, World &world){
    std::deque<std::pair<int, std::string>> resultMessages;
    std::cout << "calling say" << std::endl;
    return resultMessages;
}