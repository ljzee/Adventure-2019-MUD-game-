//
// Modified by Adrien on 2/2/2019.
//

#ifndef AREA_H
#define AREA_H

#include <string_view>
#include <vector>
#include "object.h"
#include "npc.h"
#include "room.h"
#include "reset.h"

class Area {
	private:
		std::string name;
		//list of HELPS
		std::vector<Npc> NPCS;
		std::vector<Object> OBJECTS;
		std::vector<Room> ROOMS;
		std::vector<Reset> RESETS;
		//list of SHOPS
	public:
		Area(string_view name);

		// Getters
		std::string getAreaName() const;

		// Other functions
		void initializeArea(vector<Npc> newNPCs, vector<Object> newObjects);
        void getAreaInfo();
};

#endif
//TODO: complete based on given json file