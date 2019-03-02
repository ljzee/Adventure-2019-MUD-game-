#include <memory>
#include <iostream>
#include <vector>
#include "world.h"
#include "area.h"

/** This class is currently not being used. Managers will probably be places here. Please ignore whatever is in here*/

void World::getMessageFromServer(std::string msg) {
    std::cout << "This is in the World Class. From client-server: " << msg << std::endl;
}

std::string World::getMotd() {
    std::string motd = "Welcome to Babka's World. The world is currently on development. \nWorld contents at the server window.";
    //areas.at(0).getInfo();
    return motd;
}

World::World() {
    std::cout << "World created. Initializing Dummy Contents..." << std::endl;
    initializeDummyContents();

}

void World::initializeDummyContents() {

}

