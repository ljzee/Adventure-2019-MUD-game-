#include <json.hpp>
#include <iostream>
#include <fstream>
#include "JSONParser.h"

using std::vector;
using json = nlohmann::json;

Area JSONParser::generateArea() {
    //put the JSON file to be read at the root directory of your build directory
    ifstream file("mirkwood.json");

    json deserializedJson;
    file >> deserializedJson;
    file.close();

    Area testArea{deserializedJson["AREA"]["name"].get<std::string>()};

    testArea.initializeArea(
             generateNPCs(deserializedJson),
             generateObjects(deserializedJson),
             generateRooms(deserializedJson),
             generateResets(deserializedJson)
            );

    testArea.getAreaInfo();

    return testArea;
}

vector<Npc> JSONParser::generateNPCs(json& deserializedJson) {
    vector<Npc> npcs;
    json deserializedNPCs = deserializedJson["NPCS"];

    for(auto& npc : deserializedNPCs) {
        npcs.push_back(Npc{
                npc["id"].get<int>(),
                npc["keywords"],
                npc["shortdesc"],
                npc["longdesc"],
                npc["description"]
        });
    }

    return npcs;
}

//TODO: Do we need to refactor this? It's similar with generateNPCs
vector<Object> JSONParser::generateObjects(json& deserializedJson) {
    vector<Object> objects;
    json deserializedObjects = deserializedJson["OBJECTS"];

    for(auto& obj : deserializedObjects) {

        objects.push_back(Object{
                obj["id"].get<int>(),
                obj["keywords"],
                obj["shortdesc"],
                obj["longdesc"],
                //TODO: how to handle the list of extras
        });
    }

    return objects;
}

vector<Room> JSONParser::generateRooms(json& deserializedJson) {
    vector<Room> rooms;
    json deserializedRooms = deserializedJson["ROOMS"];

    for(auto& room : deserializedRooms) {
        vector<Door> doors = generateDoors(room);
        vector<ExtendDesc> extendedDesc = generateExtendedDescriptions(room);

        rooms.push_back(Room{
                room["id"].get<int>(),
                room["name"].get<std::string>(),
                room["desc"],
                doors,
                extendedDesc
        });
    }

    return rooms;
}

vector<Door> JSONParser::generateDoors(json& deserializedJson) {
    vector<Door> doors;
    json deserializedDoor = deserializedJson["doors"];

    for(auto& door : deserializedDoor) {
        doors.push_back(Door{
                door["dir"].get<std::string>(),
                door["desc"],
                door["keywords"],
                door["to"].get<int>()
        });
    }

    return doors;
}

//Needs refactoring of how to properly assign the json values as a vector
vector<ExtendDesc> JSONParser::generateExtendedDescriptions(json& deserializedJson) {
    vector<ExtendDesc> extendedDesc;
    ExtendDesc newExtendedDesc;
    json deserializedExtendedDesc = deserializedJson["extended_descriptions"];

    for(auto& extDesc : deserializedExtendedDesc) {
        vector<std::string> keys = extDesc["keywords"];
        vector<std::string> descriptions = extDesc["keywords"];

        newExtendedDesc.keywords = keys;
        newExtendedDesc.desc = descriptions;

        extendedDesc.push_back(newExtendedDesc);
    }

    return extendedDesc;
}

vector<StructReset> JSONParser::generateResets(json& deserializedJson) {
    vector<StructReset> resets;
    json deserializedResets = deserializedJson["RESETS"];

    for (auto &reset : deserializedResets) {
        StructReset parsedStructReset;

        parsedStructReset.action = reset.value("action", "");
        parsedStructReset.id = reset.value("id", -1);
        parsedStructReset.limit = reset.value("limit", -1);
        parsedStructReset.room = reset.value("room", -1);
        parsedStructReset.slot = reset.value("slot", -1);
        parsedStructReset.state = reset.value("state", "");
        //TODO: "" and -1 to be refactored to some default variable value

        resets.push_back(parsedStructReset);
    }

    return resets;
}

std::unordered_map<int, User> JSONParser::parseUsers() {
    std::unordered_map<int, User> userList;
    int counter = 0; //temporary solution to int field of the map

    //put the JSON file to be read at the root directory of your build directory
    ifstream file("userlist.json");

    json deserializedJson;
    file >> deserializedJson;
    file.close();

    for(auto& user : deserializedJson["USERS"]) {
        std::string username = user["name"].get<std::string>();
        std::string password = user["password"].get<std::string>();

        User newUser{username};

        userList.insert({counter++, newUser});

    }

    return userList;
}