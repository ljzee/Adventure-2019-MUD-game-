//
// Created by Dev on 2019-02-09.
//

#ifndef PROJECT_COMMANDER_H
#define PROJECT_COMMANDER_H

#include <unordered_map>
#include "command.h"



class Commander {

    struct Command {

        enum Roles
        {
            Casual = 0,
            WorldBuilder
        };

        typedef std::deque<pair<int, std::string>> (Commander::*fptr) (int, std::string &, World &);
        fptr commandFunc;
        Roles role;
        bool minigameCallable;
        std::string errorMessage;
        int minimumArguments;

    };

public:
    void initializeCommandTable();
    //if avatarId is still int, change to ID type if available
    std::deque<pair<int, std::string>> processCommand(int avatarId, const std::string& command, World& world);
private:
    std::unordered_map<std::string, Command> commandTable;

    std::deque<pair<int, std::string>> processSay(int avatarId, std::string &command, World &world);
};


#endif //PROJECT_COMMANDER_H
