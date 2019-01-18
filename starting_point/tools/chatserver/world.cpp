//
// Created by Adrien on 1/17/2019.
//

#include <iostream>


class World {

public:
    void getMessageFromServer(std::string msg);
    std::string getMotd();
    World();
};

void World::getMessageFromServer(std::string msg) {
    std::cout << "This is in the World Class. From client-server: " << msg << std::endl;
}

std::string World::getMotd() {
    std::cout << "The world sent a message to the user who requested the MOTD" << std::endl;
    std::string motd = "Welcome to Babka's World. The world is currently on development.";
    return motd;
}

World::World() {
    std::cout << "World created. The word is currently empty." << std::endl;
}

