#include <json.hpp>
#include <iostream>
#include <fstream>
#include "JSONParser.h"

using std::vector;
using json = nlohmann::json;


void JSONParser::generateArea() {

    //put the JSON file to be read at the root directory of your build directory
    ifstream file("mirkwood.json");

    json deserializedJson;
    file >> deserializedJson;
    file.close();

    //Area testArea{deserializedJson["AREA"]["name"].get<std::string>()};
    //testArea.getAreaInfo();


    generateCharacters(deserializedJson);
    generateObjects(deserializedJson);
    generateRooms(deserializedJson);
    //printMap();
}

void JSONParser::generateCharacters(json& deserializedJson) {
    json deserializedCharacters = deserializedJson["NPCS"];

    std::unique_ptr<Character> characterObject;
    int id;

    for(auto& character : deserializedCharacters) {
        id = character["id"].get<int>();

        characterObject = std::make_unique<Character>(
                id,
                character["keywords"],
                character["shortdesc"].get<std::string>(),
                vectorToString(character["longdesc"]),
                vectorToString(character["description"])
        );

        characterContainer.insert(std::pair<int, std::unique_ptr<Character>>(id, std::move(characterObject)));
    }
}

//TODO: Do we need to refactor this? It's similar with generateNPCs
void JSONParser::generateObjects(json& deserializedJson) {
    json deserializedObjects = deserializedJson["OBJECTS"];

    std::unique_ptr<Object> object;
    int id;

    for(auto& obj : deserializedObjects) {
        id = obj["id"].get<int>();

        object = std::make_unique<Object>(
                id,
                obj["keywords"],
                obj["shortdesc"].get<std::string>(),
                vectorToString(obj["longdesc"])
                );

        objectContainer.insert(std::pair<int, std::unique_ptr<Object>>(id, std::move(object)));
    }
}

void JSONParser::generateRooms(json& deserializedJson) {
    json deserializedRooms = deserializedJson["ROOMS"];

    std::unique_ptr<Room> roomObject;
    int id;

    for(auto& room : deserializedRooms) {
        vector<Door> doors = generateDoors(room);
        vector<ExtendDesc> extendedDesc = generateExtendedDescriptions(room);
        id = room["id"].get<int>();

        roomObject = std::make_unique<Room>(
                id,
                room["name"].get<std::string>(),
                vectorToString(room["desc"]),
                doors,
                extendedDesc
                );

        roomContainer.insert(std::pair<int, std::unique_ptr<Room>>(id, std::move(roomObject)));
    }
}

vector<Door> JSONParser::generateDoors(json& deserializedJson) {
    vector<Door> doors;
    json deserializedDoor = deserializedJson["doors"];

    for(auto& door : deserializedDoor) {
        doors.push_back(Door{
                door["dir"].get<std::string>(),
                vectorToString(door["desc"]),
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

        //newExtendedDesc.keywords = keys;
        //newExtendedDesc.desc = descriptions;

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

std::string JSONParser::vectorToString(std::vector<std::string> vector) {
    std::string result;

    for(auto str : vector) {
        result += str + " ";
    }

    return result;
}

//For testing purposes only just so you can see the list of npcs/objects in the map -Adrien
void JSONParser::printMap() {
    for(auto const& [key, val] : roomContainer) {
        std::cout << "map key:" << key << "\n" << "map value: \n" << val->getRoomInfo() << std::endl;
    }
}

std::unordered_map<int, std::unique_ptr<Character>> JSONParser::getCharacters() {
    return std::move(characterContainer);
}

std::unordered_map<int, std::unique_ptr<Object>> JSONParser::getObjects() {
    return std::move(objectContainer);
}

std::unordered_map<int, std::unique_ptr<Room>> JSONParser::getRooms() {
    return std::move(roomContainer);
}