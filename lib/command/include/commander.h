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
 * - executing command objects for each avatarId per heartbeat
 *
 */

class Commander {

public:

    ///Constructor
    Commander(std::unique_ptr<World> world);

    ///Methods called in mudserver

    //parses command string, creates a command object and stores it in bufferedCommands
    void generateCommandObject(const networking::Connection connectionId, int avatarId, const std::string &enteredCommand);
    //executes the first command object for each avatarId's command queue
    void executeHeartbeat(UserManager &UsrMgr);

private:

    std::unique_ptr<World> world;
    int heartbeatCount = 0; //used for testing
    std::unordered_map<uintptr_t, std::deque<std::unique_ptr<Command>> > bufferedCommands;//map stores {avatarId, commandObjectQueue} pairs
    //adds a command object to commandObjectQueue of the calling avatarId, new {avatarId, commandObjectQueue} pair is added if no entry exists
    void addCommandToBuffer(std::unique_ptr<Command> commandObj);
    void respondToClient(networking::Connection conn, UserManager &UsrMgr, std::deque<std::pair<int, std::string>> messages);

};


#endif //PROJECT_COMMANDER_H
