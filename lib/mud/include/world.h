#ifndef WORLD_H
#define WORLD_H

#include <unordered_map>
#include <set>
#include <memory>
#include <boost/bimap.hpp>
#include <vector>
#include "npc.h"
#include "room.h"
#include "object.h"
#include "areaManager.h"

class World {
private:

    std::set<std::string> usedKeywords;                                          //keeps track of unusable avatar names

    std::unordered_map<int, std::unique_ptr<Npc>> npcLookupTable;                //used for resets, clone an entry
    std::unordered_map<int, std::unique_ptr<Object>> objectLookupTable;          //used for resets

    std::unordered_map<int, std::unique_ptr<Room>> rooms;                        //rooms from all areas are stored in a single container
    std::unordered_map<std::string, std::unique_ptr<AreaManager>> areaManagers;  //areaManager class in charge of resets for a single area

    std::unordered_map<int, std::unique_ptr<Npc>> activeNpcStore;                //stores all active npcs + avatars
    boost::bimap<uintptr_t, int> connectionNpcAssociation;                       //associates a connection with an avatar/npc


public:

    World();

    void insertNpcLookup(std::pair<int, std::unique_ptr<Npc>>);
    void insertObjectLookup(std::pair<int, std::unique_ptr<Object>>);
    void insertRoom(std::pair<int, std::unique_ptr<Room>>);
    void insertAreaManager(std::pair<std::string, std::unique_ptr<AreaManager>>);

    bool checkUniqueAvatarname(std::string avatarName);
    void addActiveNpc(std::string avatarName);
    void associateNpc(uintptr_t, int);

};

#endif //WORLD_H
