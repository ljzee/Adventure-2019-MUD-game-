//
// Created by Dev on 2019-03-16.
//

#include "CharacterController.h"

int CharacterController::getNextCharacterId(){
    int id = currentCharacterId;
    currentCharacterId++;
    return id;
}

bool CharacterController::CharacterController::checkCharacterName(const std::string& name){
    return (usedCharacterNames.find(name) == usedCharacterNames.end());
}

int CharacterController::createCharacter(const std::string& name){
    int assignedId = getNextCharacterId();
    std::unique_ptr character = std::make_unique<Character>(assignedId, name);
    activeCharacterStore.insert({assignedId, std::move(character)});
    usedCharacterNames.insert(name);
    return assignedId;
}

Character* CharacterController::getCharacter(int avatarId){
    auto characterEntry = activeCharacterStore.find(avatarId);
    if(characterEntry != activeCharacterStore.end()){
        return characterEntry->second.get();
    }
    return nullptr;
}