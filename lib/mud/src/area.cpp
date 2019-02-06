#include <iostream>
#include "area.h"

using namespace std;

Area::Area(string_view name) {
     this->name = name;
}

std::string Area::getAreaName() const { return this->name; }

void Area::initializeArea(vector<Npc> newNPCs, vector<Object> newObjects,
                         vector<Room> newRooms, vector<structReset> newResets) {
    NPCS = move(newNPCs);
    OBJECTS = move(newObjects);
    ROOMS = move(newRooms);
    RESETS = move(newResets);
}

void Area::getAreaInfo() {
    cout << "Area statistics. For testing if the JSON Parser is working" << endl;

    cout << "Area name: " << name << endl;

    cout << "\n# of NPCS: " << NPCS.size() << endl;

    cout << "\n# of OBJECTS: " << OBJECTS.size() << endl;

    cout << "\n# of ROOMS: " << ROOMS.size() << endl;

    int totalRooms = 0;
    for(auto& room : ROOMS) {
        totalRooms += room.getNumDoors();
    }
    cout << "\n# of DOORS: " << totalRooms << endl;

    cout << "\n# of RESETS: " << RESETS.size() << endl;

}