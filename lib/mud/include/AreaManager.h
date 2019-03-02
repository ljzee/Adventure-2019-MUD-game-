//
// AreaManager class will be responsible for Area population,
// user movement between the rooms.
//

#ifndef ADVENTURE_AREAMANAGER_H
#define ADVENTURE_AREAMANAGER_H

#include <iostream>
#include <unordered_map>
#include "area.h"

class AreaManager {

public:
    AreaManager(const std::string& pathToJSON);

private:

    std::unordered_map<std::string, Area> areas;
};


#endif //ADVENTURE_AREAMANAGER_H
