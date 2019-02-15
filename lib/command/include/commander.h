//
// Created by Dev on 2019-02-09.
//

#ifndef PROJECT_COMMANDER_H
#define PROJECT_COMMANDER_H

#include <unordered_map>
#include "command.h"
#include "commandSay.h"
#include "world.h"
#include <memory>
#include <boost/algorithm/string.hpp>

class Commander {

public:
    void initializeCommandTable();
    //if avatarId is still int, change to ID type if available
    std::deque<std::pair<int, std::string>> processCommand(int avatarId, const std::string& command, World& world);
private:
    std::unordered_map<std::string, std::unique_ptr<Command>> commandTable;

};


#endif //PROJECT_COMMANDER_H
