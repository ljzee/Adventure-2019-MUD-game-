//
// Created by Dev on 2019-03-16.
//

#ifndef ADVENTURE2019_CHARACTERCONTROLLER_H
#define ADVENTURE2019_CHARACTERCONTROLLER_H

#include <memory>
#include <set>
#include <unordered_map>

#include "Character.h"

/**
 * CharacterController Class:
 *
 * - container class to store characters
 * - contain methods to add, remove, and get a particular character
 *
 */

class CharacterController {
public:
    bool checkCharacterName(const std::string& name);
    int createCharacter(const std::string& name);

    void addActiveCharacter(std::unique_ptr<Character> characterPtr);
    void removeActiveCharacter(int avatarId);
    Character* getCharacter(int avatarId);

private:
    int currentCharacterId = 0;                                                 //keeps track of the next id to assign to a new character
    std::set<std::string> usedCharacterNames;                                   //keeps track of unusable avatar names
    std::unordered_map<int, std::unique_ptr<Character>> activeCharacterStore;   //stores all active player and non-player characters

    int getNextCharacterId();
};


#endif //ADVENTURE2019_CHARACTERCONTROLLER_H
