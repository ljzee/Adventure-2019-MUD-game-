#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "area.h"

//using namespace std;

Area::Area() {
     this->name = "Mirkwood";
}

std::string Area::getAreaName() const { return this->name; }

void Area::initializeArea() {
     Npc newNpc{};
     NPCS.push_back(newNpc);
     Object newObj{};
     OBJECTS.push_back(newObj);
     Room newRoom{};
     ROOMS.push_back(newRoom);
}

void Area::getAreaInfo() {
     cout << "Area name: " << name <<
          "\nNpc: " << NPCS.at(0).outputNpcInfo() <<
          "Object: " << OBJECTS.at(0).getObjectInfo() << endl;
}