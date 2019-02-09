#ifndef ADVENTURE_JSONPARSER_H
#define ADVENTURE_JSONPARSER_H

#include <json.hpp>
#include <vector>
#include <string>

#include "area.h"
#include "npc.h"
#include "object.h"
#include "room.h"
#include "reset.h"
#include "User.h"

using json = nlohmann::json;
using namespace std;

class JSONParser {
public:
    Area generateArea();
    vector<Npc> generateNPCs(json& deserializedJson);
    vector<Object> generateObjects(json& deserializedJson);
    vector<Room> generateRooms(json& deserializedJson);
    vector<Door> generateDoors(json& deserializedJson);
    vector<ExtendDesc> generateExtendedDescriptions(json& deserializedJson);
    vector<StructReset> generateResets(json& deserializedJson);
    std::unordered_map<int, User> parseUsers();
};


#endif //ADVENTURE_JSONPARSER_H
