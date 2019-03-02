//
// Created by Dev on 2019-02-09.
//
#include "commander.h"

///Constructor

Commander::Commander(std::unique_ptr<World> world) : world(std::move(world))
{}

///Methods called in mudserver

//parses command string, creates a command object and stores it in bufferedCommands
void Commander::generateCommandObject(const networking::Connection connection, int avatarId, const std::string &enteredCommand) {

    std::string commandToProcess = enteredCommand;
    boost::trim_if(commandToProcess, boost::is_any_of(" "));
    auto commandWord = enteredCommand.substr(0, enteredCommand.find(' '));

    // check if the avatar is in a 'session' {combat mode, mini-game, etc.}
    if((commandWord == "say") || (commandWord == "tell") || (commandWord == "yell")){
        addCommandToBuffer(std::move(std::unique_ptr<Command>(new commands::CommandCommunicate(connection, commandWord, enteredCommand))));
    }else if((commandWord == "north") || (commandWord == "south") || (commandWord == "east") || (commandWord == "west")){
        addCommandToBuffer(std::move(std::unique_ptr<Command>(new commands::CommandMove(connection, commandWord, enteredCommand))));
    }else if((commandWord == "look") || (commandWord == "examine")){
        addCommandToBuffer(std::move(std::unique_ptr<Command>(new commands::CommandLook(connection, commandWord, enteredCommand))));
    }else if((commandWord == "get") || (commandWord == "put") || (commandWord == "drop") || (commandWord == "give") || (commandWord == "wear") || (commandWord == "remove")){
        addCommandToBuffer(std::move(std::unique_ptr<Command>(new commands::CommandItem(connection, commandWord, enteredCommand))));
    }else if((commandWord == "attack") || (commandWord == "kill")){
        addCommandToBuffer(std::move(std::unique_ptr<Command>(new commands::CommandCombat(connection, commandWord, enteredCommand))));
    }else if((commandWord == "swap")){
        addCommandToBuffer(std::move(std::unique_ptr<Command>(new commands::CommandSwap(connection, commandWord, enteredCommand))));
    }else{
        addCommandToBuffer(std::move(std::unique_ptr<Command>(new commands::CommandNotExist(connection, commandWord, enteredCommand))));
    }
}

//executes the first command object for each avatarId's command queue
void Commander::executeHeartbeat(UserManager &UsrMgr) {
    std::cout << std::string("\nHeartbeat") + "(" << this->heartbeatCount << ")" << std::endl;

    for(auto& commandDeque : bufferedCommands) { // for each avatar
        if (!commandDeque.second.empty()) { // empty string?
            auto resultMessage = commandDeque.second.front()->process(*(this->world));
            commandDeque.second.pop_front();

            UsrMgr.sendMessageQueue(resultMessage);
        }
    }

    this->heartbeatCount++; //heartbeatCount used for testing
}

//adds a command object to commandObjectQueue of the calling avatarId, new {avatarId, commandObjectQueue} pair is added if no entry exists
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
