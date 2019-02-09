#ifndef ROOM_H
#define ROOM_H

#include <vector>

using std::vector;

struct ExtendDesc {
	vector<std::string> keywords, desc;
};

struct Door {
	std::string dir;
	vector<std::string> desc;
	vector<std::string> keywords;
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
		std::string name;
		vector<std::string> desc;
		vector<Door> doors;
		vector<ExtendDesc> extendedDesc;
	public:
		// Constructor
		Room(int id, std::string name, vector<std::string> desc, vector<Door> doors, vector<ExtendDesc> extendedDesc);

		// Getters
		int get_dummy_objects() const;
		int get_dummy_characters() const;
		int getID() const;
		std::string getName() const;

		// Member Functions
		std::string outputDescString();
		int getNumDoors();
		// void resetRoom();
};

#endif
