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

using namespace std;

struct extendDesc {
	std::vector<string> keywords, desc;
};

struct Door {
	std::string dir;
	std::vector<string> desc;
	std::vector<string> keywords;
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

		int ID;
		std::string name;
		std::vector<string> desc;
		std::vector<Door> doors;
		std::vector<extendDesc> extendDescs;
	public:
		// Constructor
		Room();

		// Getters
		int get_dummy_objects() const;
		int get_dummy_characters() const;
		int getID() const;
		std::string getName() const;

		// Member Functions
		std::string outputDescString();
		void resetRoom();
};

#endif
//TODO: complete based on given json file