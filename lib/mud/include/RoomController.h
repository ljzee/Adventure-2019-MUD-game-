//
// AreaManager class will be responsible for Area population,
// user movement between the rooms.
//

#ifndef ADVENTURE_AREAMANAGER_H
#define ADVENTURE_AREAMANAGER_H

#include <iostream>
#include <unordered_map>
#include "area.h"


class RoomController {

public:
    RoomController(const std::string& pathToJSON);
    // remove section
    bool removeRoom(int id);
    bool removeDoorFromRoom(int doorID, int roomID);
    // remove section

    // add section
    bool addCharacterToRoom(int npcID, int roomID);
    bool addObjectToRoom(int objectID, int roomID);
    bool addDoorToRoom(int doorID, int roomID);
    // add section

    bool moveCharacter(int currentRoomID, int newRoomID);

    // will return description of the room, description of the characters present in the room
    // and opened doors
    std::string getFullRoomDescription(int roomID);


private:

    std::unordered_map<int, Room> rooms;

    std::unordered_map<std::string, Area> areas;
};


#endif //ADVENTURE_AREAMANAGER_H
