#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include "room.h"

Room::Room(int id, std::string name, std::string desc, vector<Door> doors, vector<ExtendDesc> extendedDesc) :
    id(id),
    name(name),
    desc(desc),
    doors(std::move(doors)),
    extendedDesc(std::move(extendedDesc)) {
}

// Getters

int Room::getId() const { return this->id; }

std::string Room::getName() const { return this->name; }
std::string Room::getDesc() const { return this->desc; }
std::vector<Door> Room::getDoors() const {return this->doors; }

// Member functions
std::string Room::getRoomInfo() const {
    return name + "\n" + desc;
}


void Room::addCharacter(int characterId) {
    characters.push_back(characterId);
}

void Room::removeCharacter(int characterId) {
    characters.erase(std::remove(characters.begin(), characters.end(), characterId), characters.end());
}

std::vector<int> Room::getAllCharactersInRoom(){
    return characters;
}

void Room::addDoor(Door door){
    doors.push_back(door);
}

bool Room::hasDoor(const std::string& doorName){
    auto result = std::find_if(doors.begin(), doors.end(),
                               [doorName](const Door & door) -> bool {return door.dir == doorName; });
    if(result != doors.end()){
        return true;
    }
    return false;
}

int Room::getDoorId(const std::string& doorName){
    auto result = std::find_if(doors.begin(), doors.end(),
                               [doorName](const Door & door) -> bool {return door.dir == doorName; });
    if(result != doors.end()){
        return result->to;
    }
    return -1;
}

std::vector<int> Room::getAdjacentRoomIds(){
    std::vector<int> adjacentRoomIds;

    for(auto door: doors){
        adjacentRoomIds.push_back(door.to);
    }

    return adjacentRoomIds;
}
/*
 void Room::resetRoom() {
	int arbitrary_limit = 100;
	dummy_characters = rand() % arbitrary_limit;
	dummy_objects = rand() % arbitrary_limit;
}
*/
