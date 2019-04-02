#include "world.h"

World::World(std::unique_ptr<RoomController> roomController,
             std::unique_ptr<CharacterController> characterController,
             std::unique_ptr<AssociationController> associationController)
              : roomController(std::move(roomController)),
                characterController(std::move(characterController)),
                associationController(std::move(associationController)){

}

std::pair<World::CharacterCreationStatus, int> World::createCharacter(const std::string& name){
    if(characterController->checkCharacterName(name)){
        int characterId = characterController->createCharacter(name);
        return {World::CharacterCreationStatus::creation_success, characterId};
    }
    return {World::CharacterCreationStatus::name_taken, -1};
}

std::string World::placeCharacter(int characterId){

    Character* characterPtr = characterController->getCharacter(characterId);

    if(characterPtr != nullptr){
        int roomId = characterPtr->getLocation();
        Room* roomPtr = roomController->getRoom(roomId);
        if(roomPtr != nullptr){
            roomPtr->addCharacter(characterId);
            return getRoomEntitiesDescription(roomId);
        }

        return std::string("Unable to place character");
    }
    return std::string("Unable to place character");
}

std::string World::selectCharacter(networking::Connection connection, int characterId){
    associationController->addAssociation(connection.id, characterId);
    std::string roomDesc = placeCharacter(characterId);
    return roomDesc;
}

void World::removeAssociation(networking::Connection connection){
    int characterId = associationController->getCharacterId(connection.id);
    Character* characterPtr = characterController->getCharacter(characterId);
    if(characterPtr != nullptr){
        int roomId = characterPtr->getLocation();
        Room* roomPtr = roomController->getRoom(roomId);
        if(roomPtr != nullptr){
            roomPtr->removeCharacter(characterId);
        }
    }
    associationController->removeAssociation(connection.id);
}

std::string World::getRoomCharactersDescription(int roomId){
    Room* roomPtr = roomController->getRoom(roomId);
    std::string roomCharacterDescription = std::string("");

    if(roomPtr != nullptr){
        auto roomCharacters = roomPtr->getAllCharactersInRoom();
        for(auto characterId : roomCharacters){
            roomCharacterDescription = roomCharacterDescription + characterController->getCharacter(characterId)->getShortDesc() + " is here.\n";
        }
    }

    return roomCharacterDescription;
}

std::string World::getRoomEntitiesDescription(int roomId){
    Room* roomPtr = roomController->getRoom(roomId);
    std::string roomEntitiesDescription = std::string("");

    if(roomPtr != nullptr){
        roomEntitiesDescription =  std::string("\n") +
                                   roomPtr->getName() + "\n" +
                                   roomController->getRoomDoorsDescription(roomId) + "\n" +
                                   roomPtr->getDesc() + "\n" +
                                   getRoomCharactersDescription(roomId);
    }

    return roomEntitiesDescription;
}

std::vector<uintptr_t> World::getRelevantPlayerConnections(networking::Connection messageCreator, const std::string& communicationMethod){
    std::vector<uintptr_t> relevantPlayerConnection;

    int characterId = associationController->getCharacterId(messageCreator.id);
    Character* characterPtr = characterController->getCharacter(characterId);
    int currentRoomId = characterPtr->getLocation();
    Room* roomPtr = roomController->getRoom(currentRoomId);

    if(communicationMethod == "say" || "yell"){
        auto characterIds = roomPtr->getAllCharactersInRoom();
        for(auto curId : characterIds){
            uintptr_t connectionId = associationController->getConnectionId(curId);
            if(connectionId != -1){
                relevantPlayerConnection.push_back(connectionId);
            }
        }
    }

    if(communicationMethod == "yell"){
        std::vector<int> adjacentRoomIds = roomPtr->getAdjacentRoomIds();

        for(auto roomId : adjacentRoomIds){
            Room* curRoomPtr = roomController->getRoom(roomId);
            auto characterIds = curRoomPtr->getAllCharactersInRoom();
            for(auto curId : characterIds){
                uintptr_t connectionId = associationController->getConnectionId(curId);
                if(connectionId != -1){
                    relevantPlayerConnection.push_back(connectionId);
                }
            }
        }
    }

    return relevantPlayerConnection;
}

std::pair<World::TargetPlayerStatus, uintptr_t> World::getTargetPlayerConnection(networking::Connection messageCreator, const std::string& characterName){
    int characterId = associationController->getCharacterId(messageCreator.id);
    Character* characterPtr = characterController->getCharacter(characterId);
    int currentRoomId = characterPtr->getLocation();
    Room* roomPtr = roomController->getRoom(currentRoomId);
    auto characterIds = roomPtr->getAllCharactersInRoom();

    for(auto curId : characterIds){
        Character* curCharacterPtr = characterController->getCharacter(curId);
        if(curCharacterPtr->getShortDesc() == characterName){
            return {World::TargetPlayerStatus::in_room, associationController->getConnectionId(curId)};
        }
    }

    return {World::TargetPlayerStatus::not_in_room, 0};
}

World::MovementStatus World::moveCharacter(std::string direction, networking::Connection connection){

    //get the associated character id
    int characterId = associationController->getCharacterId(connection.id);
    Character* characterPtr = characterController->getCharacter(characterId);
    int currentRoomId = characterPtr->getLocation();
    Room* roomPtr = roomController->getRoom(currentRoomId);

    if(roomPtr->hasDoor(direction)){
        int targetRoomId = roomPtr->getDoorId(direction);
        auto moveStatus = roomController->moveCharacter(currentRoomId, targetRoomId, characterId);
        if(moveStatus){
            characterPtr->updateLocation(targetRoomId);
            return World::movement_success;
        }else{
            return World::movement_failed;
        }
    }
    return World::door_not_exist;


}

std::string World::getCharacterName(networking::Connection connection){
    int characterId = associationController->getCharacterId(connection.id);
    Character* characterPtr = characterController->getCharacter(characterId);
    return characterPtr->getShortDesc();
}

int World::getCharacterLocation(networking::Connection connection){

    int characterId = associationController->getCharacterId(connection.id);
    Character* characterPtr = characterController->getCharacter(characterId);
    return characterPtr->getLocation();

}