//
// Created by Alex on 1/18/2019.
//

//
// Modified by Andre on 1/25/2019.
//

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "room.h"

//Will be read in from JSON, so dummy values for now
Room::Room(int id, string name, vector<string> desc, vector<Door> doors, vector<extendDesc> extendDescs) {
    this->id = id;
    this->name = name;
    this->desc = desc;
    this->doors = doors;
    this->extendDescs = extendDescs;

    /*
    this->dummy_objects = 1;
    this->dummy_characters = 1;
    this->ID = 8800;
    this->name = "Entrance to Mirkwood";
    this->desc.push_back("You have entered the quasi-magical Elven forest of Mirkwood, populated by");
    this->desc.push_back("Sylvan Elves and their mysterious allies. Strangers are frowned upon here,");
    this->desc.push_back("so be on your guard. It is rumored that many different races of Elves");
    this->desc.push_back("actually inhabit this forest, in various parts and sometimes they are");
    this->desc.push_back("carefully hidden, away from the prying eyes of strangers.");
    this->desc.push_back("There is a sign tacked to a tree nearby.");

    // dummy Door struct
    Door daDoor;
    daDoor.dir = "south";
    daDoor.desc.push_back("You see the marketplace.");
    daDoor.keywords.push_back("door");
    daDoor.to = 10503;
    this->doors.push_back(daDoor);

    // dummy extendDesc struct
    extendDesc ed;
    ed.keywords.push_back("sign");
    ed.desc.push_back("This area serves as a connector for many areas with an Elven or Faerie");
    ed.desc.push_back("flavour, favored areas of the Immortal Yaegar. Tread carefully, and remember");
    ed.desc.push_back("to keep track of where you have been.");
    ed.desc.push_back("");
    ed.desc.push_back("--Yaegar");
    this->extendDescs.push_back(ed);
    */
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

/*
 void Room::resetRoom() {
	int arbitrary_limit = 100;
	dummy_characters = rand() % arbitrary_limit;
	dummy_objects = rand() % arbitrary_limit;
}
*/



// NOTES FOR SEVA:
// Isee the google doc again

//TODO: implement room.h