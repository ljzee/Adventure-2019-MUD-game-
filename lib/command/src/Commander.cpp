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
using networking::Message;


std::unordered_map<std::string, std::function<std::unique_ptr<Command>(networking::Connection, std::string, std::string)>> Commander::commandMap = [](){

    std::unordered_map<std::string, std::function<std::unique_ptr<Command>(networking::Connection, std::string, std::string)>> map;
    auto notExistKeywords = NotExistCommandsHelper::values();
    std::for_each(notExistKeywords.begin(), notExistKeywords.end(), [&](NotExistCommands c) {
        map.emplace(NotExistCommandsHelper::to_string(c), [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::CommandNotExist>(id, commandWord, command);});
    });
    
    auto commKeywords = CommCommandsHelper::values();
    std::for_each(commKeywords.begin(), commKeywords.end(), [&](CommCommands c) {
        map.emplace(CommCommandsHelper::to_string(c), [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::Communicate>(id, commandWord, command);});
    });


    auto moveKeywords = MoveCommandsHelper::values();
    std::for_each(moveKeywords.begin(), moveKeywords.end(), [&](MoveCommands c) {
        map.emplace(MoveCommandsHelper::to_string(c), [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::Move>(id, commandWord, command);});
    });

    auto lookKeywords = LookCommandsHelper::values();
        std::for_each(lookKeywords.begin(), lookKeywords.end(), [&](LookCommands c) {
        map.emplace(LookCommandsHelper::to_string(c), [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::Look>(id, commandWord, command);});
    });

    auto itemKeywords = ItemCommandsHelper::values();
    std::for_each(itemKeywords.begin(), itemKeywords.end(), [&](ItemCommands c) {
        map.emplace(ItemCommandsHelper::to_string(c), [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::CommandItem>(id, commandWord, command);});
    });

    auto combatKeywords = CombatCommandsHelper::values();
    std::for_each(combatKeywords.begin(), combatKeywords.end(), [&](CombatCommands c) {
        map.emplace(CombatCommandsHelper::to_string(c), [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::CommandCombat>(id, commandWord, command);});
    });

    auto swapKeywords = SwapCommandsHelper::values();
    std::for_each(swapKeywords.begin(), swapKeywords.end(), [&](SwapCommands c) {
        map.emplace(SwapCommandsHelper::to_string(c), [&](networking::Connection id, std::string commandWord, std::string command) {return std::make_unique<commands::CommandSwap>(id, commandWord, command);});
    });
    return map;
}();



//parses command string, creates a command object and stores it in bufferedCommands
std::unique_ptr<Command> Commander::createNewCommand(const Message& msg) {
    
    std::string text = msg.text;
    boost::trim_if(text, boost::is_any_of(" "));
    boost::to_lower(text);
    auto commandWord = text.substr(0, text.find(' '));
    auto command = commandMap.find(commandWord);

    if(command != commandMap.end()) {
        return command->second(msg.connection, commandWord, text);
    }
    else {
        return commandMap[NotExistCommandsHelper::to_string(NotExistCommands::NOTEXIST)](msg.connection, commandWord, text);
    }
}