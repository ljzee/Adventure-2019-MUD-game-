//
// Created by Adrien on 2/1/2019.
//

//
// Modified by Andre on 2/4/2019.
//

#include <json.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "JSONParser.h"


using json = nlohmann::json;
using namespace std;

Area JSONParser::generateArea() {

    ifstream file("mirkwood.json");

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

        vector<Door> doors = generateDoors(room);
        vector<extendDesc> extendedDesc = generateExtendedDescriptions(room);

        rooms.push_back(Room{
                room["id"].get<int>(),
                room["name"].get<string>(),
                room["desc"], // room["desc"]
                doors, // room["doors"]
                extendedDesc // room["extended_descriptions"]
        });
    }

    return rooms;
}

vector<Door> JSONParser::generateDoors(json& deserializedJson) {
    vector<Door> doors;
    json deserializedDoor = deserializedJson["doors"];

    for(auto& door : deserializedDoor) {

        doors.push_back(Door{
                door["dir"].get<string>(),
                door["desc"],
                door["keywords"],
                door["to"].get<int>()
        });
    }

    return doors;
}

//Needs refactoring of how to properly assign the json values as a vector
vector<extendDesc> JSONParser::generateExtendedDescriptions(json& deserializedJson) {
    vector<extendDesc> extendedDesc;
    extendDesc newExtendedDesc;
    json deserializedExtendedDesc = deserializedJson["extended_descriptions"];

    for(auto& extDesc : deserializedExtendedDesc) {
        vector<string> keys = extDesc["keywords"];
        vector<string> descriptions = extDesc["keywords"];

        newExtendedDesc.keywords = keys;
        newExtendedDesc.desc = descriptions;

        extendedDesc.push_back(newExtendedDesc);
    }

    return extendedDesc;
}

vector<structReset> JSONParser::generateResets(json& deserializedJson) {
    vector<structReset> resets;
    json deserializedResets = deserializedJson["RESETS"];

    for (auto &reset : deserializedResets) {
        structReset parsedStructReset;

        /*parsedStructReset.action = reset["action"].get<string>();
        parsedStructReset.id = reset["id"].get<int>();
        parsedStructReset.limit = reset["limit"].get<int>();
        parsedStructReset.room = reset["room"].get<int>();
        parsedStructReset.slot = reset["slot"].get<int>();
        parsedStructReset.state = reset["state"].get<string>();*/

        parsedStructReset.action = reset.value("action", "");
        parsedStructReset.id = reset.value("id", -1);
        parsedStructReset.limit = reset.value("limit", -1);
        parsedStructReset.room = reset.value("room", -1);
        parsedStructReset.slot = reset.value("slot", -1);
        parsedStructReset.state = reset.value("state", "");

        resets.push_back(parsedStructReset);
    }

    return resets;
}

std::unordered_map<int, User> JSONParser::parseUsers() {
    std::unordered_map<int, User> userList;
    int counter = 0; //temporary solution to int field of the map

    ifstream file("userlist.json");

    json deserializedJson;
    file >> deserializedJson;
    file.close();

    for(auto& user : deserializedJson["USERS"]) {
        std::string username = user["name"].get<string>();
        std::string password = user["password"].get<string>();

        User newUser{username, password};

        userList.insert({counter++, newUser});

    }

    //for testing purposes only:
    for(auto& u : userList) {
        std::cout << u.first << " => " << u.second.getUsername() << "\t" << u.second.getPassword() << std::endl;
    }
    return userList;
}