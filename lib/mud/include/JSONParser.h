//
// Created by Adrien on 2/1/2019.
//

#ifndef ADVENTURE_JSONPARSER_H
#define ADVENTURE_JSONPARSER_H

#include <json.hpp>
#include <vector>

#include "area.h"
#include "npc.h"
#include "object.h"
#include "room.h"
#include "reset.h"



using json = nlohmann::json;
using namespace std;

class JSONParser {
public:
    Area generateArea();
    vector<Npc> generateNPCs(json& deserializedJson);
    vector<Object> generateObjects(json& deserializedJson);
    vector<Room> generateRooms(json& deserializedJson);
    vector<structReset> generateResets(json& deserializedJson);

};


#endif //ADVENTURE_JSONPARSER_H
