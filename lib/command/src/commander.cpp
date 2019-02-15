//
// Created by Dev on 2019-02-09.
//
#include "commander.h"

void Commander::initializeCommandTable() {
    commandTable.insert({"say", std::unique_ptr<Command>(new CommandSay("say", Command::Casual, true, 2, "say [message]"))});
}



std::deque<std::pair<int, std::string>> Commander::processCommand(int avatarId, const std::string &command,
                                                                  World &world) {
    std::deque<std::pair<int, std::string>> resultMessages;

    std::string commandToProcess = command;
    boost::trim_if(commandToProcess, boost::is_any_of(" "));
    auto commandWord = commandToProcess.substr(0, commandToProcess.find(' '));

    auto commandEntry = commandTable.find(std::string(commandWord));
    if(commandEntry != commandTable.end()){
        commandEntry->second->process(avatarId, commandToProcess, world);
    }

    return resultMessages;

}

