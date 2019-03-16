#include <iostream>
#include "area.h"

Area::Area(std::string name) : name(name) {}

std::string Area::getName() const { return this->name; }

void Area::initializeArea(vector<Character> newNpcs, vector<Object> newObjects,
                         vector<Room> newRooms, vector<StructReset> newResets) {

    Npcs = std::move(newNpcs);
    Objects = std::move(newObjects);
    Rooms = std::move(newRooms);
    Resets = std::move(newResets);
}

void Area::getInfo() {

    std::cout << "Area name: " << name << std::endl;

    std::cout << "\n# of NPCS: " << Npcs.size() << std::endl;

    std::cout << "\n# of OBJECTS: " << Objects.size() << std::endl;

    std::cout << "\n# of ROOMS: " << Rooms.size() << std::endl;

    std::cout << "\n# of RESETS: " << Resets.size() << std::endl;
}