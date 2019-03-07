#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>
#include <area.h>
#include <unordered_map>
#include <deque>
#include <memory>
#include "UserManager.h"

using namespace std;

class World {
private:
    vector<Area> areas;
    

public:
    void getMessageFromServer(std::string msg);
    void initializeDummyContents();
    string getMotd();
    World();

    //void update(UserManager& usrMgr);
};

#endif //WORLD_H
