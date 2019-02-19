//
// Created by Dev on 2019-02-09.
//
#include "commander.h"

///Methods called in mudserver

//parses command string, creates a command object and stores it in bufferedCommands
void Commander::generateCommandObject(int avatarId, const std::string &enteredCommand) {
    std::string commandToProcess = enteredCommand;
    boost::trim_if(commandToProcess, boost::is_any_of(" "));
    auto commandWord = enteredCommand.substr(0, enteredCommand.find(' '));
    if(commandWord == "say"){
         addCommandToBuffer(std::move(std::unique_ptr<Command>(new commands::CommandSay(avatarId, enteredCommand))));
    }else{
        addCommandToBuffer(std::move(std::unique_ptr<Command>(new commands::CommandNotExist(avatarId, enteredCommand))));
    }
}

//executes the first command object for each avatarId's command queue
void Commander::executeHeartbeat(World& world) {
    std::cout << std::string("\nHeartbeat") + "(" << this->heartbeatCount << ")" << std::endl;
    for(auto& commandDeque : bufferedCommands) {
        if (!commandDeque.second.empty()) {
            int avatarId = commandDeque.first;
            commandDeque.second.front()->process(world);
            commandDeque.second.pop_front();
        }
    }
    this->heartbeatCount++; //heartbeatCount used for testing
}

//adds a command object to commandObjectQueue of the calling avatarId, new {avatarId, commandObjectQueue} pair is added if no entry exists
void Commander::addCommandToBuffer(std::unique_ptr<Command> commandObj) {
    auto avatarId = commandObj->caller;
    auto avatarCommandDeque = bufferedCommands.find(avatarId);
    if(avatarCommandDeque != bufferedCommands.end()){
        avatarCommandDeque->second.push_back(std::move(commandObj));
    }else{
        std::deque<std::unique_ptr<Command>> newCommandDeque;
        newCommandDeque.push_back(std::move(commandObj));
        bufferedCommands.insert({avatarId, std::move(newCommandDeque)});
    }
}

