#include "Move.h"

namespace commands {
    Move::Move(const networking::Connection connection,
                             const std::string &commandWord,
                             const std::string &enteredCommand) : Command(connection, commandWord, enteredCommand)
                             {}

    Move::~Move(){}

    std::deque<std::pair<uintptr_t , std::string>> Move::process(std::unique_ptr<World>& world) {
        //Messages to return to affected user(s)
        std::deque<std::pair<uintptr_t, std::string>> resultMessages;

        auto moveResult = world->moveCharacter(commandWord, callerConnection);
        if(moveResult == World::movement_success){
            std::string roomEntitiesDescription = world->getRoomEntitiesDescription(world->getCharacterLocation(callerConnection));
            resultMessages.push_back({callerConnection.id, roomEntitiesDescription});
        }else if(moveResult == World::door_not_exist){
            resultMessages.push_back({callerConnection.id, "This door does not exist!"});
        }else if(moveResult == World::door_locked){
            resultMessages.push_back({callerConnection.id, "This door is locked! You must unlock it first"});
        }else{
            resultMessages.push_back({callerConnection.id, "Movement failed."});
        }

        return resultMessages;
    }
}