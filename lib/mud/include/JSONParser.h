#ifndef ADVENTURE_JSONPARSER_H
#define ADVENTURE_JSONPARSER_H

#include "json.hpp"
#include <vector>
#include <string>

#include "area.h"
#include "Character.h"
#include "object.h"
#include "room.h"
#include "reset.h"
#include "User.h"

using json = nlohmann::json;
using namespace std;

class JSONParser {
private:
    std::unordered_map<int, std::unique_ptr<Character>> characterContainer;
    std::unordered_map<int, std::unique_ptr<Object>> objectContainer;
    std::unordered_map<int, std::unique_ptr<Room>> roomContainer;
public:

    void parseAreaJsonFiles();
    void generateArea(const char * fileName);
    void generateCharacters(json& deserializedJson);
    void generateObjects(json& deserializedJson);
    void generateRooms(json& deserializedJson);
    vector<Door> generateDoors(json& deserializedJson);
    vector<ExtendDesc> generateExtendedDescriptions(json& deserializedJson);
    vector<StructReset> generateResets(json& deserializedJson);
    std::unordered_map<int, User> parseUsers();
    std::string vectorToString(std::vector<std::string> vector);
    void printMap();
    std::unordered_map<int, std::unique_ptr<Character>> getCharacters();
    std::unordered_map<int, std::unique_ptr<Object>> getObjects();
    std::unordered_map<int, std::unique_ptr<Room>> getRooms();
};


#endif //ADVENTURE_JSONPARSER_H
