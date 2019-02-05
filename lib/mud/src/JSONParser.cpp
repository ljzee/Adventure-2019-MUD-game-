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
             generateObjects(deserializedJson)
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
