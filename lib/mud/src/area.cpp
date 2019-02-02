//
// Modified by Adrien on 2/2/2019.
//

#include <iostream>
#include "area.h"

using namespace std;

Area::Area(string_view name) {
     this->name = name;
}

std::string Area::getAreaName() const { return this->name; }

void Area::initializeArea(vector<Npc> newNPCs, vector<Object> newObjects) {
    NPCS = move(newNPCs);
    OBJECTS = move(newObjects);
}

void Area::getAreaInfo() {
     cout << "Area name: " << name << endl;

     cout << "\nNPC List: \n" << endl;
     for(auto& npc : NPCS) {
          cout << npc.outputNpcInfo() << endl;
     }

     cout << "\nObject List: \n" << endl;
     for(auto& obj : OBJECTS) {
          cout << obj.getObjectInfo() << endl;
     }
}