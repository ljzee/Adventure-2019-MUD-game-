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

    //read and load from JSON to be managed in JSONParser

    // ITEMS ===================================================================
    void addItem(std::unique_ptr<baseItem> item);
    void removeItem(itemID);

    const std::unique_ptr<baseItem> itemLookup(itemID id) const;

    // INVENTORY ================================================================

private:

    std::map<itemID, std::unique_ptr<baseItem> > itemMap;
    std::map<int, Inventory> InventoryMap;

};

#endif //ADVENTURE2019_ITEMMANAGER_H
