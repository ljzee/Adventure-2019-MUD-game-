//
// Created by Andrew on 2019-02-19.
//

#ifndef ADVENTURE2019_ITEM_H
#define ADVENTURE2019_ITEM_H

#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <memory>

namespace item {

    typedef int itemID;

    class baseItem {

    public:
        enum itemType {
            CONSUMABLE, EQUIPMENT, MISC
        };
        baseItem();
        baseItem(itemType type, std::string name, std::string desc, bool quest, bool droppable);
        virtual std::unique_ptr<baseItem> clone() const = 0;

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
        usableItem(std::string name, std::string desc, bool isQuest, bool isDroppable,
                       int eID, int sellVal);
        virtual std::unique_ptr<baseItem> clone() const override {
            return std::make_unique<usableItem>(*this);
        }

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
                  int slot, int atk, int def, int eID);
        std::unique_ptr<baseItem> clone() const override {
            return std::make_unique<usableItem>(*this);
        }

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
        virtual std::unique_ptr<baseItem> clone() const override {
            return std::make_unique<miscItem>(*this);
        }

    private:
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
