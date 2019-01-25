//
// Created by Adrien on 1/17/2019.
//

#ifndef WORLD_H
#define WORLD_H

#include <iostream>

class World {

public:
    void getMessageFromServer(std::string msg, uintptr_t id);
    std::string getMotd();
    World();
};

#endif //WORLD_H
