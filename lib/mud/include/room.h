#ifndef ROOM_H
#define ROOM_H

#include <vector>

using std::vector;

struct ExtendDesc {
	vector<std::pair<std::string, std::string>> keywordDescriptionPair;
};

struct Door {
	std::string dir;
	std::string desc;
	vector<std::string> keywords;
	int to;
};

class Room {
	private:

		int id;
		std::string name;
		std::string desc;
		vector<Door> doors;
		vector<ExtendDesc> extendedDesc;

	public:
		// Constructor
		Room(int id, std::string name, std::string desc, vector<Door> doors, vector<ExtendDesc> extendedDesc);

		// Getters
		int getID() const;
		std::string getName() const;

		// Member Functions
		std::string outputDescString();
		int getNumDoors();
		// void resetRoom();
};

#endif
