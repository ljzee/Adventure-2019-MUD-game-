//
// Created by Alex on 1/18/2019.
//

//
// Modified by Andrea on 1/24/2019.
//

//
// Modified by Andre on 1/25/2019.
//

#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>

using std::string;
using std::vector;

struct extendDesc {
	vector<string> keywords, desc;
};

struct Door {
	string dir;
	vector<string> desc;
	vector<string> keywords;
	int to;
};

class Room {
	private:
		int dummy_objects; // need to change type for later
		int dummy_characters;
		// include in-game objects
		// include characters
		// include other(?)
		// include POINTERS to other rooms; what kind of functions do we need?
		// use an arbitrary new room

		int id;
		string name;
		vector<string> desc;
		vector<Door> doors;
		vector<extendDesc> extendDescs;
	public:
		// Constructor
		Room(int id, string name, vector<string> desc, vector<Door> doors, vector<extendDesc> extendDescs);

		// Getters
		int get_dummy_objects() const;
		int get_dummy_characters() const;
		int getID() const;
		string getName() const;

		// Member Functions
		string outputDescString();
		int getNumDoors();
		// void resetRoom();
};

#endif
//TODO: complete based on given json file