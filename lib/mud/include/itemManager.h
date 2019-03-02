//
// Created by Andrew on 2019-02-19.
//

#ifndef ADVENTURE2019_ITEMMANAGER_H
#define ADVENTURE2019_ITEMMANAGER_H

namespace item;

typedef int itemID;

class itemManager {
public:



private:
    std::unordered_map<itemID, baseItem*> itemTable;

};

#endif //ADVENTURE2019_ITEMMANAGER_H
