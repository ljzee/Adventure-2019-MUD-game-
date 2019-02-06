#include <iostream>
#include <string>
#include <stdlib.h> 
#include <time.h>
#include "room.h"


Room::Room(int id, string name, vector<string> desc, vector<Door> doors, vector<extendDesc> extendDescs) {
    this->id = id;
    this->name = name;
    this->desc = desc;
    this->doors = doors;
    this->extendDescs = extendDescs;
}

// Getters
int Room::get_dummy_characters() const { return this->dummy_characters; }

int Room::get_dummy_objects() const { return this->dummy_objects; }

int Room::getID() const { return this->id; }

string Room::getName() const { return this->name; }

// Member functions
string Room::outputDescString() {

    string concatDesc = "";
    for (auto &portion : this->desc) {
        concatDesc +=  portion;
        concatDesc += "\n";
    }

    return concatDesc;
}

int Room::getNumDoors() {
    return doors.size();
};

/*
 void Room::resetRoom() {
	int arbitrary_limit = 100;
	dummy_characters = rand() % arbitrary_limit;
	dummy_objects = rand() % arbitrary_limit;
}
*/
