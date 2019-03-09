//
// Created by Andrew on 2019-02-19.
//

#ifndef ADVENTURE2019_ITEM_H
#define ADVENTURE2019_ITEM_H

#include <string>
#include <vector>
#include <unordered_map>

namespace item {

    typedef int itemID;

    class baseItem {

    public:
        enum itemType {
            CONSUMABLE, EQUIPMENT, MISC
        };

        baseItem(int type, std::string name, std::string desc, bool quest, bool droppable);

        // Getters
        const itemType getType() const { return itemClass; };

        const std::string getName() const { return itemName; };

        const std::string getDesc() const { return itemDesc; };

    private:
        itemType itemClass;

        std::string itemName;
        std::string itemDesc;

        bool isQuestItem;
        bool isDroppable;
    };

// CONSUMABLES
    class usableItem : public baseItem {

    public:
        usableItem(int);

        const int getEffect() const { return effectID; };
        //const std::string getModifiers() const {return modifiers;};
    private:
        int effectID;
        int sellValue;
        //vector<std::string> modifiers;
    };


// EQUIPMENT
    class equipItem : public baseItem {

    public:
        equipItem();

    private:
        int equipSlot;

        int baseDef;
        int baseAtk;
        int effectID;

        //vector<std::string> modifiers;
        int sellValue;
    };


// MISCELLANEOUS
    class miscItem : public baseItem {

    public:
        miscItem();

    private:
    };

    class Inventory {
    public:
        static const int maxQuant = 99;

        Inventory(int maxSize);

        const bool checkOwnItem(int itemID) const;
        const bool checkItemQuantity(int itemID) const;
        const int checkInvSize() {return invSize;};
        const std::string listItems() const;

        bool addItem(int itemID, int quantity);
        bool removeItem(int itemID, int Quantity);

        bool alterInvSize(int newSize);



    private:
        // invContainer maps an item's itemID to its quantity within the inventory.
        std::unordered_map<itemID, int> invContainer;
        int invSize = 10;

    };


}

#endif //ADVENTURE2019_ITEM_H
