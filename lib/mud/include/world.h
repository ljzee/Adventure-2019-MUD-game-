#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>
#include <area.h>

using namespace std;

class World {
private:
    vector<Area> areas;

public:
    void getMessageFromServer(std::string msg);
    void initializeDummyContents();
    string getMotd();
    World();
};

#endif //WORLD_H
