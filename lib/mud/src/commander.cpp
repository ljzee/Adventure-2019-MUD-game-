//
// Created by Dev on 2019-02-09.
//

#include "commander.h"

void Commander::initializeCommandTable() {
    Command say = {&Commander::processSay, Command::Casual, true, "Call command say by: say [message]", 2};

    commandTable.insert({"say", say});
}

std::deque<pair<int, std::string>> Commander::processCommand(int avatarId, const std::string &command, World &world) {
    std::deque<pair<int, std::string>> resultMessages;

    std::string commandToSplit = command;
    auto result = commandTable.find(std::string("say"));
    if(result != commandTable.end()){
        auto cmd = result->second;
        return (this->*cmd.commandFunc)(avatarId, commandToSplit, world);
    }

    return resultMessages;
}

std::deque<pair<int, std::string>> Commander::processSay(int avatarId, std::string &command, World &world) {
    std::deque<pair<int, std::string>> resultMessages;
    std::cout << "calling say" << std::endl;
    return resultMessages;
}