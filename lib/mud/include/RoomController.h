//
// AreaManager class will be responsible for Area population,
// user movement between the rooms.
//

#ifndef ADVENTURE_AREAMANAGER_H
#define ADVENTURE_AREAMANAGER_H

#include <iostream>
#include <unordered_map>
#include "room.h"


class RoomController {

public:
    //RoomController(const std::string& pathToJSON);
    RoomController(std::unordered_map<int, std::unique_ptr<Room>> rooms);
    void removeRoom(int roomId);
    Room* getRoom(int roomId);

    std::string getRoomDoorsDescription(int roomId);
    bool moveCharacter(int from, int to, int characterId);

    int getNumberOfRooms();

private:

    std::unordered_map<int, std::unique_ptr<Room>> rooms;
};


#endif //ADVENTURE_AREAMANAGER_H
