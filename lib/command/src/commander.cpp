//
// Created by Dev on 2019-02-09.
//
#include "commander.h"

///Methods called in mudserver

//parses command string, creates a command object and stores it in bufferedCommands
void Commander::generateCommandObject(const networking::Connection connectionID, int avatarId, const std::string &enteredCommand) {
    std::string commandToProcess = enteredCommand;
    boost::trim_if(commandToProcess, boost::is_any_of(" "));
    // check if the avatar is in a 'session' {combat mode, mini-game, etc.}
    addCommandToBuffer(std::move(
            std::unique_ptr<Command>(new Command(connectionID, avatarId, enteredCommand))
                    ));
}

//executes the first command object for each avatarId's command queue
void Commander::executeHeartbeat(World& world, UserManager &UsrMgr) {
    std::cout << std::string("\nHeartbeat") + "(" << this->heartbeatCount << ")" << std::endl;
    for(auto& commandDeque : bufferedCommands) { // for each avatar
        if (!commandDeque.second.empty()) { // empty string?
            int avatarId = commandDeque.first; // first 'key' is avatarID
            networking::Connection connectionID = commandDeque.second.front()->getConnectionID();
            Commander::respondToClient(connectionID, UsrMgr, commandDeque.second.front()->process(world));// process the first command obj in the list
            commandDeque.second.pop_front(); // remove from list
        }
    }

    this->heartbeatCount++; //heartbeatCount used for testing
}

//adds a command object to commandObjectQueue of the calling avatarId, new {avatarId, commandObjectQueue} pair is added if no entry exists
void Commander::addCommandToBuffer(std::unique_ptr<Command> commandObj) {
    auto avatarId = commandObj->getCaller();
    auto avatarCommandDeque = bufferedCommands.find(avatarId);
    if(avatarCommandDeque != bufferedCommands.end()){
        avatarCommandDeque->second.push_back(std::move(commandObj));
    }else{
        std::deque<std::unique_ptr<Command>> newCommandDeque;
        newCommandDeque.push_back(std::move(commandObj));
        bufferedCommands.insert({avatarId, std::move(newCommandDeque)});
    }
}

void  Commander::respondToClient(networking::Connection conn, UserManager &UsrMgr, std::deque<std::pair<int, std::string>> messages) {
    UsrMgr.sendMessage(conn, "executing command");
}