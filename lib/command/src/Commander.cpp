// 
// Created by Dev on 2019-02-09.
//
#include "Commander.h"
#include "Combat.h"
#include "Communicate.h"
#include "Move.h"
#include "CommandItem.h"
#include "Look.h"
#include "CommandNotExist.h"
#include "Swap.h"
#include <boost/algorithm/string.hpp>


using namespace commands;

Commander::Commander(std::unique_ptr<World> world) : world(std::move(world)) {
    setUpFunctionMap();
}

void Commander::setUpFunctionMap() {
    auto notExistKeywords = CommandNotExist::values;
    std::for_each(notExistKeywords.begin(), notExistKeywords.end(), [this](const std::string& c) {
        commandMap.emplace(c, [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::CommandNotExist>(id, commandWord, command);});
    });
    
    auto commKeywords = Communicate::values;
    std::for_each(commKeywords.begin(), commKeywords.end(), [this](const std::string& c) {
        commandMap.emplace(c, [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::Communicate>(id, commandWord, command);});
    });

    auto moveKeywords = Move::values;
    std::for_each(moveKeywords.begin(), moveKeywords.end(), [this](const std::string& c) {
        commandMap.emplace(c, [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::Move>(id, commandWord, command);});
    });

    auto lookKeywords = Look::values;
        std::for_each(lookKeywords.begin(), lookKeywords.end(), [this](const std::string& c) {
        commandMap.emplace(c, [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::Look>(id, commandWord, command);});
    });

    auto itemKeywords = CommandItem::values;
    std::for_each(itemKeywords.begin(), itemKeywords.end(), [this](const std::string& c) {
        commandMap.emplace(c, [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::CommandItem>(id, commandWord, command);});
    });

    auto combatKeywords = CommandCombat::values;
    std::for_each(combatKeywords.begin(), combatKeywords.end(), [this](const std::string& c) {
        commandMap.emplace(c, [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::CommandCombat>(id, commandWord, command);});
    });

    auto swapKeywords = CommandSwap::values;
    std::for_each(swapKeywords.begin(), swapKeywords.end(), [this](const std::string& c) {
        commandMap.emplace(c, [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::CommandSwap>(id, commandWord, command);});
    });
}


//parses command string, creates a command object and stores it in bufferedCommands
void Commander::createNewCommand(const networking::Connection connectionId, const std::string &enteredCommand) {
    
    std::string commandToProcess = enteredCommand;
    boost::trim_if(commandToProcess, boost::is_any_of(" "));
    auto commandWord = enteredCommand.substr(0, enteredCommand.find(' '));
    auto command = commandMap.find(commandWord);
    if(command != commandMap.end()) {
        addCommandToBuffer(command->second(connectionId, commandWord, enteredCommand));
    }
    else {
        addCommandToBuffer(commandMap["notExist"](connectionId, commandWord, enteredCommand));
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
void Commander::addCommandToBuffer(std::unique_ptr<Command> command) {
    auto connectionId = command->getCallerConnectionId();
    auto avatarCommandDeque = bufferedCommands.find(connectionId);
    if(avatarCommandDeque != bufferedCommands.end()){
        avatarCommandDeque->second.push_back(std::move(command));
    }else{
        std::deque<std::unique_ptr<Command>> newCommandDeque;
        newCommandDeque.push_back(std::move(command));
        bufferedCommands.insert({connectionId, std::move(newCommandDeque)});
    }


}
