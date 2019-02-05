//
// Created by Adrien on 2/1/2019.
//

#include <json.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "JSONParser.h"


using json = nlohmann::json;
using namespace std;

Area JSONParser::generateArea() {

    ifstream file("shire.json");

    json deserializedJson;
    file >> deserializedJson;
    file.close();

    Area testArea{deserializedJson["AREA"]["name"].get<string>()};

    testArea.initializeArea(
             generateNPCs(deserializedJson),
             generateObjects(deserializedJson),
             generateRooms(deserializedJson),
             generateResets(deserializedJson)
             //other objects in here
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
        // Parsing room "description" information
        json deserializedDesc = room["desc"];
        vector<string> parsedDesc;
        for(auto& str : deserializedDesc) {
            parsedDesc.push_back(str.get<string>());
        }

        // Parsing door information
        json deserializedDoor = room["doors"];
        vector<Door> parsedDoor;
        vector<string> doorDesc;
        vector<string> doorKeywords;
        Door daDoor = {"", doorDesc, doorKeywords, -1};
        for(auto& door : deserializedDoor) {
                daDoor.dir = door["dir"].get<string>();
                for(auto& str : door["desc"]) {
                    daDoor.desc.push_back(str.get<string>());
                }
                for(auto& word : door["keywords"]) {
                    daDoor.keywords.push_back(word.get<string>());
                }
                daDoor.to = door["to"].get<int>();
                parsedDoor.push_back(daDoor);
        }

        // Parsing extended description information
        json deserializedExtendedDesc = room["extended_descriptions"];
        vector<extendDesc> parsedExtendDesc;
        extendDesc daExtendDesc = {vector<string>(), vector<string>()};
        for(auto& extDesc : deserializedExtendedDesc) {
            for(auto& word : extDesc["keywords"]) {
                daExtendDesc.keywords.push_back(word.get<string>());
            }
            for(auto& str : extDesc["desc"]) {
                daExtendDesc.desc.push_back(str.get<string>());
            }
            parsedExtendDesc.push_back(daExtendDesc);
        }

        rooms.push_back(Room{
                room["id"].get<int>(),
                room["name"].get<string>(),
                parsedDesc, // room["desc"]
                parsedDoor, // room["doors"]
                parsedExtendDesc // room["extended_descriptions"]
        });
    }

    return rooms;
}


vector<structReset> JSONParser::generateResets(json& deserializedJson) {
    vector<structReset> resets;
    json deserializedResets = deserializedJson["RESETS"];

    for (auto &reset : deserializedResets) {
        structReset parsedStructReset;

        parsedStructReset.action = reset["action"].get<string>();
        parsedStructReset.id = reset["id"].get<int>();
        parsedStructReset.limit = reset["limit"].get<int>();
        parsedStructReset.room = reset["room"].get<int>();
        parsedStructReset.slot = reset["slot"].get<int>();
        parsedStructReset.state = reset["state"].get<string>();

        resets.push_back(parsedStructReset);
    }

    return resets;
}