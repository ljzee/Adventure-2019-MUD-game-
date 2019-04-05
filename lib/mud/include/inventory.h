#pragma once

#include "itemManager.h"

using namespace item;
// INVENTORY
    class Inventory {
    public:
        static const int maxQuant = 99;

        Inventory(int invSize);

        std::unique_ptr<item::baseItem> referenceItem(itemManager& IM, itemID id);

        const bool checkItem(itemID itemID) const;

        const bool checkItemQuant(itemID itemID) const;
        const int checkInvSize() const {return maxSize;};
        const std::string listItems(itemManager& IM) const;

        bool addItem(itemID item, int quantity);
        int removeItem(itemID item, int quantity);

        void alterInvSize(int newSize);


    private:
        // invContainer maps an item's itemID to its quantity within the inventory.
        std::unordered_map<itemID, int> invContainer;
        int maxSize;
        int curSize;

    };
