#ifndef AREA_H
#define AREA_H

#include <vector>
#include "object.h"
#include "npc.h"
#include "room.h"
#include "reset.h"

class Area {
	private:
		std::string name;
		//list of HELPS
		std::vector<Npc> Npcs;
		std::vector<Object> Objects;
		std::vector<Room> Rooms;
		std::vector<StructReset> Resets;
		//list of SHOPS
	public:
		Area(std::string name);

		// Getters
		std::string getAreaName() const;

		// Other functions
		void initializeArea(vector<Npc> newNpcs, vector<Object> newObjects,
				vector<Room> newRooms, vector<StructReset> newResets);
        void getAreaInfo();
};

#endif