//
// Created by Adrien on 1/17/2019.
//

#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include "world.h"
#include "area.h"


using namespace std;

void World::getMessageFromServer(std::string msg) {
    cout << "This is in the World Class. From client-server: " << msg << endl;
}

std::string World::getMotd() {
    std::string motd = "Welcome to Babka's World. The world is currently on development. \nWorld contents at the server window.";
    areas.at(0).getAreaInfo();
    return motd;
}

World::World() {
    cout << "World created. Initializing Dummy Contents..." << endl;
    initializeDummyContents();
}

void World::initializeDummyContents() {
    Area newArea{};
    newArea.initializeArea();
    areas.push_back(newArea);

    cout << "Dummies initialized" << endl;
}

