//
// Created by Dev on 2019-02-09.
//
#include "commander.h"

///Constructor

Commander::Commander(std::unique_ptr<World> world) : world(std::move(world))
{}

///Methods called in mudserver

//parses command string, creates a command object and stores it in bufferedCommands
void Commander::createNewCommand(const networking::Connection connectionId, const std::string &enteredCommand) {

    std::string commandToProcess = enteredCommand;
    boost::trim_if(commandToProcess, boost::is_any_of(" "));
    auto commandWord = enteredCommand.substr(0, enteredCommand.find(' '));

    // say

    // check if the avatar is in a 'session' {combat mode, mini-game, etc.}
    if((commandWord == "say") || (commandWord == "tell") || (commandWord == "yell")){
        addCommandToBuffer(std::move(std::unique_ptr<Command>(new commands::Communicate(connectionId, commandWord, enteredCommand))));
    }else if((commandWord == "north") || (commandWord == "south") || (commandWord == "east") || (commandWord == "west")){
        addCommandToBuffer(std::move(std::unique_ptr<Command>(new commands::Move(connectionId, commandWord, enteredCommand))));
    }else if((commandWord == "look") || (commandWord == "examine")){
        addCommandToBuffer(std::move(std::unique_ptr<Command>(new commands::Look(connectionId, commandWord, enteredCommand))));
    }else if((commandWord == "get") || (commandWord == "put") || (commandWord == "drop") || (commandWord == "give") || (commandWord == "wear") || (commandWord == "remove")){
        addCommandToBuffer(std::move(std::unique_ptr<Command>(new commands::CommandItem(connectionId, commandWord, enteredCommand))));
    }else if((commandWord == "attack") || (commandWord == "kill")){
        addCommandToBuffer(std::move(std::unique_ptr<Command>(new commands::CommandCombat(connectionId, commandWord, enteredCommand))));
    }else if((commandWord == "swap")){
        addCommandToBuffer(std::move(std::unique_ptr<Command>(new commands::CommandSwap(connectionId, commandWord, enteredCommand))));
    }else{
        addCommandToBuffer(std::move(std::unique_ptr<Command>(new commands::CommandNotExist(connectionId, commandWord, enteredCommand))));
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
void Commander::addCommandToBuffer(std::unique_ptr<Command> commandObj) {
    auto connectionId = commandObj->getCallerConnectionId();
    auto avatarCommandDeque = bufferedCommands.find(connectionId);
    if(avatarCommandDeque != bufferedCommands.end()){
        avatarCommandDeque->second.push_back(std::move(commandObj));
    }else{
        std::deque<std::unique_ptr<Command>> newCommandDeque;
        newCommandDeque.push_back(std::move(commandObj));
        bufferedCommands.insert({connectionId, std::move(newCommandDeque)});
    }


}
