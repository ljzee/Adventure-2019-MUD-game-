//
// Created by Andrew on 2019-02-19.
//

#ifndef ADVENTURE2019_ITEM_H
#define ADVENTURE2019_ITEM_H

#include "itemManager.h"

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

        baseItem(itemType type, std::string name, std::string desc, bool quest, bool droppable);

        // Getters
        const itemType getType() const { return itemClass; };
        const std::string getName() const { return itemName; };
        const std::string getDesc() const { return itemDesc; };
        const bool getIsQuest() const {return isQuestItem; };
        const bool getIsDroppable() const {return isDroppable; };
        const int getSellValue() const {return sellValue; };

        // Setters
        void alterName(std::string newName);
        void alterDesc(std::string newDesc);
        void alterQuest(bool isQuest);
        void alterDroppable(bool isDroppable);
        void alterSellValue(int newValue);

    private:
        itemType itemClass;

        std::string itemName;
        std::string itemDesc;
        bool isQuestItem;
        bool isDroppable;

        int sellValue;
    };

// CONSUMABLES
    class usableItem : public baseItem {

    public:
        usableItem(int itemEffect, sellValue);

        // Getters
        const int getEffect() const { return effectID; };
        const int getMagnitude() const {return effectMagnitude; };
        //const std::string getModifiers() const {return modifiers;};

        // Setters
        void alterEffect(int newEffectID);
        void alterMagnitude(int newEffectMag);

    private:
        int effectID;
        int effectMagnitude;
        //vector<std::string> modifiers;
    };


// EQUIPMENT
    class equipItem : public baseItem {

    public:

        equipItem(std::string name, std::string desc, bool isQuest, bool isDroppable,
                  int slot, int atk, int def, int eID)

        // Getters
        const int getSlot() const {return equipSlot; };
        const int getAtkVal() const {return baseAtk; };
        const int getDef() const {return baseDef; };
        const int getEffectID() const {return effectID; };

        // Setters
        void alterAtk(int newAtk);
        void alterDef(int newDef);
        void alterEffect(int newEffectID);

    private:
        int equipSlot;
        int baseAtk;
        int baseDef;
        int effectID;

        //vector<std::string> modifiers;
    };


// MISCELLANEOUS
    class miscItem : public baseItem {

    public:
        miscItem();

    private:
    };


// INVENTORY
    class Inventory {
    public:
        static const int maxQuant = 99;

        Inventory(int invSize);

        const bool checkItem(int itemID) const;
        const bool findItem(itemManager IM, std::string itemName) const;
        const bool checkItemQuant(int itemID) const;
        const int checkInvSize() const {return invSize;};
        const std::string listItems(itemManager IM) const;

        bool addItem(itemID item, int quantity);
        bool removeItem(itemID item, int Quantity);

        bool alterInvSize(int newSize);


    private:
        // invContainer maps an item's itemID to its quantity within the inventory.
        std::unordered_map<itemID, int> invContainer;
        int maxSize;
        int curSize;
    };


    /*
object::Chest : public baseObject{
public:
    Inventory(10)
    lookinchest{inventory.check}
    getfromchest{inventory.get};
private:

};
*/
}

#endif //ADVENTURE2019_ITEM_H
