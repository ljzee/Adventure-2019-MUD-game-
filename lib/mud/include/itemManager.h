//
// Created by Andrew on 2019-02-19.
//

#ifndef ADVENTURE2019_ITEMMANAGER_H
#define ADVENTURE2019_ITEMMANAGER_H

#include "item.h"
#include "inventory.h"
#include <utility>
#include <unordered_map>

namespace item {

    typedef int itemID;

    class itemManager {
    public:

        //read and load from JSON to be managed in JSONParser

        // ITEMS ===================================================================
        void addItem(std::unique_ptr <baseItem> item);

        void removeItem(itemID id);

        const std::unique_ptr <baseItem> itemLookup(itemID id) const;

        // INVENTORY ================================================================

    private:

        std::unordered_map<itemID, std::unique_ptr<baseItem>> itemMap;
        std::unordered_map<itemID, Inventory> InventoryMap;

    };
}

#endif //ADVENTURE2019_ITEMMANAGER_H
