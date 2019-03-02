//
// Created by Andrew on 2019-02-19.
//

#ifndef ADVENTURE2019_ITEM_H
#define ADVENTURE2019_ITEM_H

// To-Dos: add clone functionality and behavior for each type

namespace item;

class baseItem {

public:
    enum itemType{CONSUMABLE, EQUIPMENT, MISC};

    baseItem(int id, int type, std::string name, std::string desc);

    // Getters
    const int getID() const {return itemID;};
    const itemType getType() const {return itemClass;};
    const std::string getName() const {return itemName;};
    const std::string getDesc() const {return itemDesc;};

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
    usableItem(int );
    const int getEffect() const {return effectID;};
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





#endif //ADVENTURE2019_ITEM_H
