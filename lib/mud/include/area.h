#ifndef AREA_H
#define AREA_H

#include <vector>
#include "object.h"
#include "npc.h"
#include "room.h"
#include "reset.h"

using namespace std;

class Area {
	private:
		string name;
		//list of HELPS
		vector<Npc> NPCS;
		vector<Object> OBJECTS;
		vector<Room> ROOMS;
		vector<Reset> RESETS;
		//list of SHOPS
	public:
        void getAreaInfo();
        Area();
        void initializeArea();
};

#endif
//TODO: complete based on given json file