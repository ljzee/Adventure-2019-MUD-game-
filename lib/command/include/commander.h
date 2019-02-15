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

class Commander {

public:
    static std::unique_ptr<Command> generateCommandObject(const networking::Message& userCommand);


};


#endif //PROJECT_COMMANDER_H
