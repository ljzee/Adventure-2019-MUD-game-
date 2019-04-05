//
// Created by Andrew on 2019-02-19.
//

#include "item.h"

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using namespace item;

// baseItem =======================================================

baseItem::baseItem(itemType type, std::string name, std::string desc, bool quest, bool droppable)
    : itemClass(MISC)
    , itemName(name)
    , itemDesc(desc)
    , isQuestItem(quest)
    , isDroppable(droppable)
    , sellValue(0);
{ }

void baseItem::alterName(std::string newName){
    //name validating?
    this->itemName = newName;
}

void baseItem::alterDesc(std::string newDesc) {
    //description string validating?
    this->itemDesc = newDesc;
}

void baseItem::alterQuest(bool isQuest){
    this->isQuestItem = isQuest;
};

void baseItem::alterDroppable(bool isDroppable){
    this->isDroppable = isDroppable;
}

void baseItem::alterSellValue (int newValue){
    this->sellValue = newValue;
}

// usableItem =======================================================

usableItem::usableItem(std::string name, std::string desc, bool isQuest, bool isDroppable,
                       int eID, int sellVal)
    : baseItem(CONSUMABLE, name, desc, isQueset, isDroppable)
    , effectId(eID)
    , sellValue(sellVal)
{ }

void usableItem::alterEffect(int newEffectID){
    // check valid effect id?
    this->effectID = newEffectID;
}

void usableItem::alterMagnitude(int newEffectMag){
    this->effectMagnitude = newEffectMag;
}

// equipItem =======================================================

equipItem::equipItem(std::string name, std::string desc, bool isQuest, bool isDroppable,
                     int slot, int atk, int def, int eID, int sellVal)
    : baseItem(EQUIPMENT, name, desc, isQuest, isDroppable, sellVal)
    , equipSlot(slot)
    , baseAtk(atk)
    , baseDef(def)
    , effectID(eID)
{ }

void equipItem::alterAtk(int newAtk){
    this->baseAtk = newAtk;
}

void equipItem::alterDef(int newDef){
    this->baseDef = newDef;
}

void equipItem::alterEffect(int newEffectID){
    this->effectID = newEffectID;
}


// miscItem =======================================================

miscItem::miscItem(std::string name, std::string desc, bool, isQuest, bool isDroppable, int sellVal)
    : baseItem(MISC, name, desc, isQuest, isDroppable, sellVal)
{}


// Inventory =======================================================


