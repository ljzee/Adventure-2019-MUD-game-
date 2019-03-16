//
// Created by Dev on 2019-02-09.
//

#ifndef PROJECT_COMMANDER_H
#define PROJECT_COMMANDER_H

#include <unordered_map>
#include "Command.h"
#include "world.h"
#include "Server.h"
#include "UserManager.h"
#include <memory>
#include <boost/algorithm/string.hpp>

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
    //parses command string, creates a command object and stores it in bufferedCommands
    static std::unique_ptr<Command> createNewCommand(const networking::Message& msg);

private:
    Commander();
    
    static std::unordered_map<std::string, std::function<std::unique_ptr<Command>(networking::Connection, std::string, std::string)>> commandMap;

};


#endif //PROJECT_COMMANDER_H
