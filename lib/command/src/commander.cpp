//
// Created by Dev on 2019-02-09.
//
#include "commander.h"
#include <boost/algorithm/string.hpp>
///Constructor



Commander::Commander(std::unique_ptr<World> world) : world(std::move(world)) {
    setUpFunctionMap();
}

void Commander::setUpFunctionMap() {
    // Communication
    commandMap["say"] = [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::Communicate>(id, commandWord, command);};
    commandMap["yell"] = commandMap["say"];
    commandMap["tell"] = commandMap["say"];
    // Moving
    commandMap["north"] = [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::Move>(id, commandWord, command);};
    commandMap["south"] = commandMap["north"];
    commandMap["east"] = commandMap["north"];
    commandMap["west"] = commandMap["north"];
    // Looking around
    commandMap["look"] = [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::Look>(id, commandWord, command);};
    commandMap["examine"] = commandMap["look"];
    // Item interaction
    commandMap["get"] = [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::CommandItem>(id, commandWord, command);};
    commandMap["put"] = commandMap["get"];
    commandMap["drop"] = commandMap["get"];
    commandMap["give"] = commandMap["get"];
    commandMap["wear"] = commandMap["get"];
    commandMap["remove"] = commandMap["get"];
    // Combat
    commandMap["attack"] = [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::CommandCombat>(id, commandWord, command);};
    commandMap["kill"] = commandMap["attack"];
    // Swap
    commandMap["swap"] = [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::CommandSwap>(id, commandWord, command);};
    //
    commandMap["notExist"] = [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::CommandNotExist>(id, commandWord, command);};

}

///Methods called in mudserver

//parses command string, creates a command object and stores it in bufferedCommands
void Commander::createNewCommand(const networking::Connection connectionId, const std::string &enteredCommand) {

    std::string commandToProcess = enteredCommand;
    boost::trim_if(commandToProcess, boost::is_any_of(" "));
    auto commandWord = enteredCommand.substr(0, enteredCommand.find(' '));
    auto command = commandMap.find(commandWord);
    if(command != commandMap.end()) {
        addCommandToBuffer(command->second(connectionId, commandWord, enteredCommand));
    }
    else {
        addCommandToBuffer(commandMap["notExist"](connectionId, commandWord, enteredCommand));
    }
}

//executes the first command object for each avatarId's command queue
void Commander::executeHeartbeat(UserManager &UsrMgr) {
    std::cout << std::string("\nHeartbeat") + "(" << this->heartbeatCount << ")" << std::endl;

    for(auto& [_, queue] : bufferedCommands) {
        if (!queue.empty()) {
            auto resultMessages = queue.front()->process(this->world);
            queue.pop_front();

            UsrMgr.sendMessageQueue(resultMessages);
        }
    }

    this->heartbeatCount++;
}

//adds a command object to commandObjectQueue of the calling avatarId, new {connection, commandObjectQueue} pair is added if no entry exists
void Commander::addCommandToBuffer(std::unique_ptr<Command> command) {
    auto connectionId = command->getCallerConnectionId();
    auto avatarCommandDeque = bufferedCommands.find(connectionId);
    if(avatarCommandDeque != bufferedCommands.end()){
        avatarCommandDeque->second.push_back(std::move(command));
    }else{
        std::deque<std::unique_ptr<Command>> newCommandDeque;
        newCommandDeque.push_back(std::move(command));
        bufferedCommands.insert({connectionId, std::move(newCommandDeque)});
    }


}
