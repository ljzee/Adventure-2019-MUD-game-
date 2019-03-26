//
// Created by Andrew on 2019-02-19.
//

#ifndef ADVENTURE2019_ITEMMANAGER_H
#define ADVENTURE2019_ITEMMANAGER_H

#include "item.h"
#include <utility>

namespace item;

typedef int itemID;

class itemManager {
public:

    //define item methods per class
    void addItem(std::unique_ptr<baseItem> item);
    void removeItem(itemID);

private:

    std::map<itemID, std::unique_ptr<baseItem>> itemMap;
    std::map<int, Inventory> InventoryMap;

};

#endif //ADVENTURE2019_ITEMMANAGER_H
