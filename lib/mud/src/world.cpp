#include "world.h"

World::World(std::unique_ptr<RoomController> roomController,
             std::unique_ptr<CharacterController> characterController,
             std::unique_ptr<AssociationController> associationController)
              : roomController(std::move(roomController)),
                characterController(std::move(characterController)),
                associationController(std::move(associationController)){

}

std::pair<World::CharacterCreationStatus, int> World::createCharacter(networking::Connection connection, const std::string& name){
    if(characterController->checkCharacterName(name)){
        int characterId = characterController->createCharacter(name);
        associationController->addAssociation(connection.id, characterId);
        return {World::CharacterCreationStatus::creation_success, characterId};
    }
    return {World::CharacterCreationStatus::name_taken, -1};
}

std::string World::placeNewCharacter(networking::Connection connection){

    int characterId = associationController->getCharacterId(connection.id);
    Room* roomPtr = roomController->getRoom(8800);
    Character* characterPtr = characterController->getCharacter(characterId);

    if((roomPtr != nullptr) && (characterPtr != nullptr)){
        roomPtr->addCharacter(characterId);
        characterPtr->updateLocation(roomPtr->getId());
    }
    return getRoomEntitiesDescription(8800);
}

void World::removeAssociation(networking::Connection connection){
    associationController->removeAssociation(connection.id);
}

std::string World::getRoomCharactersDescription(int roomId){
    Room* roomPtr = roomController->getRoom(roomId);
    std::string roomCharacterDescription = std::string("");

    if(roomPtr != nullptr){
        auto roomCharacters = roomPtr->getAllCharactersInRoom();
        for(auto characterId : roomCharacters){
            roomCharacterDescription = roomCharacterDescription + characterController->getCharacter(characterId)->getShortDesc() + " is here.";
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

int World::getCharacterLocation(networking::Connection connection){
    int characterId = associationController->getCharacterId(connection.id);
    Character* characterPtr = characterController->getCharacter(characterId);

    if(characterPtr != nullptr){
        return characterPtr->getLocation();
    }

    return -1;
}

bool World::hasDoor(int roomId, const std::string& doorName){
    Room* roomPtr = roomController->getRoom(roomId);

    if(roomPtr != nullptr){
        return roomPtr->hasDoor(doorName);
    }

    return false;
}

int World::getDoorTargetRoomId(int roomId, const std::string& doorName){
    Room* roomPtr = roomController->getRoom(roomId);

    if(roomPtr != nullptr){
        return roomPtr->getDoorId(doorName);
    }

    return -1;
}

bool World::moveCharacter(int from, int to, networking::Connection connection){
    int characterId = associationController->getCharacterId(connection.id);
    Character* characterPtr = characterController->getCharacter(characterId);
    Room* fromRoomPtr = roomController->getRoom(from);
    Room* toRoomPtr = roomController->getRoom(to);

    if((fromRoomPtr != nullptr) && (toRoomPtr != nullptr)){
        fromRoomPtr->removeCharacter(characterId);
        toRoomPtr->addCharacter(characterId);

        characterPtr->updateLocation(to);
        return true;
    }

    return false;
}