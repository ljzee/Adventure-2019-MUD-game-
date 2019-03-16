#ifndef WORLD_H
#define WORLD_H

#include <unordered_map>
#include <set>
#include <memory>
#include <boost/bimap.hpp>
#include <vector>
#include "Character.h"
#include "room.h"
#include "object.h"

class World {
private:

    std::set<std::string> userCharacterNames;                                          //keeps track of unusable avatar names

    std::unordered_map<int, std::unique_ptr<Character>> characterLookupTable;          //used for resets, clone an entry
    std::unordered_map<int, std::unique_ptr<Object>> objectLookupTable;                //used for resets

    std::unordered_map<int, std::unique_ptr<Room>> rooms;                              //rooms from all areas are stored in a single container

    std::unordered_map<int, std::unique_ptr<Character>> activeCharacterStore;          //stores all active npcs + avatars
    boost::bimap<uintptr_t, int> connectionCharacterAssociation;                       //associates a connection with an avatar/npc


public:

    World();

    bool checkUniqueAvatarname(std::string avatarName);
    void addActiveCharacter(std::string avatarName);
    void associateCharacter(uintptr_t, int);

};

#endif //WORLD_H
