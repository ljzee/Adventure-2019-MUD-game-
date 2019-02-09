#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include "room.h"

Room::Room(int id, std::string name, vector<std::string> desc, vector<Door> doors, vector<ExtendDesc> extendedDesc) :
    id(id),
    name(name),
    desc(std::move(desc)),
    doors(std::move(doors)),
    extendedDesc(std::move(extendedDesc)) {
}

// Getters
int Room::get_dummy_characters() const { return this->dummy_characters; }

int Room::get_dummy_objects() const { return this->dummy_objects; }

int Room::getID() const { return this->id; }

std::string Room::getName() const { return this->name; }

// Member functions
std::string Room::outputDescString() {

    std::string concatDesc = "";
    for (auto &portion : this->desc) {
        concatDesc +=  portion;
        concatDesc += "\n";
    }

    return concatDesc;
}

/*
 void Room::resetRoom() {
	int arbitrary_limit = 100;
	dummy_characters = rand() % arbitrary_limit;
	dummy_objects = rand() % arbitrary_limit;
}
*/
