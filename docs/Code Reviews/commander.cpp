//
// Created by Dev on 2019-02-09.
//

#ifndef PROJECT_COMMANDER_H
#define PROJECT_COMMANDER_H

#include <unordered_map>
#include "command.h"
#include "commandDeclaration.h"
#include "world.h"
#include <memory>
#include <boost/algorithm/string.hpp>
#include "Server.h"

/**
 * Commander Class:
 *
 * - responsible for converting string commands into command objects
 * - container to store queued up command objects to be executed for each heartbeat
 * - executing command objects for each connection per heartbeat
 *
 */

class Commander {

public:

    ///Constructor
    Commander(std::unique_ptr<World> world);

    ///Methods called in mudserver

    //parses command string, creates a command object and stores it in bufferedCommands
    void generateCommandObject(const networking::Connection connectionId, const std::string &enteredCommand);
    //executes the first command object for each connection's command queue
    void executeHeartbeat(UserManager &UsrMgr);

private:

    std::unique_ptr<World> world;
    int heartbeatCount = 0;
    std::unordered_map<uintptr_t, std::deque<std::unique_ptr<Command>> > bufferedCommands;//map stores {avatarId, commandObjectQueue} pairs

    void addCommandToBuffer(std::unique_ptr<Command> commandObj);
    void respondToClient(networking::Connection conn, UserManager &UsrMgr, std::deque<std::pair<int, std::string>> messages);

};


#endif //PROJECT_COMMANDER_H



//
// Created by Dev on 2019-02-09.
//
#include "commander.h"

///Constructor

Commander::Commander(std::unique_ptr<World> world) : world(std::move(world))
{}

///Methods called in mudserver

//parses command string, creates a command object and stores it in bufferedCommands
void Commander::generateCommandObject(const networking::Connection connection, const std::string &enteredCommand) {

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

    for(auto& commandDeque : bufferedCommands) {
        if (!commandDeque.second.empty()) {
            auto resultMessages = commandDeque.second.front()->process(*(this->world));
            commandDeque.second.pop_front();

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
