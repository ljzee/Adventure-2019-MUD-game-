//
// Created by Vsevolod on 2019-03-01.
//

#include <boost/filesystem.hpp>
#include "RoomController.h"
#include "JSONParser.h"

using namespace boost::filesystem;

/*
RoomController::RoomController(const std::string& pathToJSONFolder) {
    JSONParser json;
    if(is_directory(pathToJSONFolder)) {
        std::cout << "Debug info. Check area population" << std::endl;
        for (auto &entry : boost::make_iterator_range(directory_iterator(pathToJSONFolder), {})) {
            Area area = json.generateArea(entry.path().string());
            areas.insert({area.getName(), area});
            std::cout << entry << "\n";
        }
    }
}
*/

RoomController::RoomController(std::unordered_map<int, std::unique_ptr<Room>> rooms)
                              : rooms(std::move(rooms)){

}

Room* RoomController::getRoom(int roomId){
    auto roomEntry = rooms.find(roomId);
    if(roomEntry != rooms.end()){
        return roomEntry->second.get();
    }
    return nullptr;
}

std::string RoomController::getRoomDoorsDescription(int roomId){
    auto roomEntry = rooms.find(roomId);
    std::string doorDescriptions = std::string("");
    auto doors = roomEntry->second->getDoors();
    for(auto door : doors){
        if(rooms.find(door.to) != rooms.end()) {
            doorDescriptions = doorDescriptions + door.dir + "-" + rooms.find(door.to)->second->getName() + " ";
        }
    }
    return doorDescriptions;
}

int RoomController::getNumberOfRooms(){
    return rooms.size();
}