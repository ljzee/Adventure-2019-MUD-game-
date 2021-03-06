#ifndef AREA_H
#define AREA_H

#include <vector>
#include "object.h"
#include "Character.h"
#include "room.h"
#include "reset.h"

class Area {
	private:
		std::string name;
		//list of HELPS
		std::vector<Character> Npcs;
		std::vector<Object> Objects;
		std::vector<Room> Rooms;
		std::vector<StructReset> Resets;
		//list of SHOPS
	public:
		Area(std::string name);

		// Getters
		std::string getName() const;

		// Other functions
		void initializeArea(vector<Character> newNpcs, vector<Object> newObjects,
				vector<Room> newRooms, vector<StructReset> newResets);
        void getInfo();
};

#endif