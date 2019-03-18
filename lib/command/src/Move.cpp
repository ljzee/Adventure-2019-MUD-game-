#include "Move.h"

namespace commands {
    Move::Move(const networking::Connection connection,
                             const std::string &commandWord,
                             const std::string &enteredCommand) : Command(connection, commandWord, enteredCommand)
                             {}

    Move::~Move(){}

    std::deque<std::pair<uintptr_t , std::string>> Move::process(std::unique_ptr<World>& world) {
        std::deque<std::pair<uintptr_t, std::string>> resultMessages;

        int roomId = world->getCharacterLocation(callerConnection);
        if(world->hasDoor(roomId, commandWord)){
            int targetRoomId = world->getDoorTargetRoomId(roomId, commandWord);
            bool moveResult = world->moveCharacter(roomId, targetRoomId, callerConnection);
            if(moveResult){
                resultMessages.push_back({callerConnection.id, world->getRoomEntitiesDescription(targetRoomId)});
            }
        }else{
            resultMessages.push_back({callerConnection.id, "You cannot go in that direction."});
        }

        return resultMessages;
    }
}