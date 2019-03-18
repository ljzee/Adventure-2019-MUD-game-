//
// Created by Dev on 2019-03-16.
//

#include "AssociationController.h"

void AssociationController::addAssociation(uintptr_t connectionId, int characterId){
    connectionIdToCharacterId.insert({connectionId, characterId});
    characterIdToConnectionId.insert({characterId, connectionId});
}

void AssociationController::removeAssociation(uintptr_t connectionId){
    auto result = connectionIdToCharacterId.find(connectionId);
    if(result != connectionIdToCharacterId.end()){
        characterIdToConnectionId.erase(result->second);
        connectionIdToCharacterId.erase(result->first);
    }
}

uintptr_t AssociationController::getConnectionId(int characterId){
    auto result = characterIdToConnectionId.find(characterId);
    if(result != characterIdToConnectionId.end()){
        return result->second;
    }
    return -1;
}

int AssociationController::getCharacterId(uintptr_t connectionId){
    auto result = connectionIdToCharacterId.find(connectionId);
    if(result != connectionIdToCharacterId.end()){
        return result->second;
    }
    return -1;
}

