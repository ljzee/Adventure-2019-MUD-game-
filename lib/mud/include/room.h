#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <algorithm>

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
public:
	// Constructor
	Room(int id, std::string name, std::string desc, vector<Door> doors, vector<ExtendDesc> extendedDesc);

	// Getters
	int getId() const;
	std::string getName() const;
	std::string getDesc() const;
	std::vector<Door> getDoors() const;
	// Member Functions
	std::string getRoomInfo() const;
	// void resetRoom();


	void addCharacter(int characterId);
	void removeCharacter(int characterId);
	std::vector<int> getAllCharactersInRoom();

	void addDoor(Door door);
	bool hasDoor(const std::string& doorName);
	int getDoorId(const std::string& doorName);
	std::vector<int> getAdjacentRoomIds();

private:

	int id;
	std::string name;
	std::string desc;
	vector<Door> doors;
	vector<ExtendDesc> extendedDesc;
	vector<int> characters;

};

#endif
