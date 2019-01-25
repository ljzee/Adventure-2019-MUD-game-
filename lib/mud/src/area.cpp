#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "area.h"
#include "npc.h"
#include "object.h"

using namespace std;

Area::Area() {
     name = "Mirkwood";
}


void Area::initializeArea() {
     Npc newNpc{};
     NPCS.push_back(newNpc);
     Object newObj{};
     OBJECTS.push_back(newObj);
}

void Area::getAreaInfo() {
     cout << "Area name: " << name <<
               "\nNpc: " << NPCS.at(0).getNpcInfo() <<
               "Object: " << OBJECTS.at(0).getObjectInfo() << endl;
}