//
// Created by Andrew on 2019-02-19.
//

#include "item.h"

#include <iostream>
#include <string>
#include <unordered_map>

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
    : baseItem(CONSUMABLE, name, desc, isQueset, isDroppable, sellVal)
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

Inventory::Inventory(int invSize)
    : maxSize(invSize)
    , curSize(0){

}

bool Inventory::checkItem(int itemID) {
    auto exists = invContainer.find(itemID);
    return (exists == invContainer.end());
}

bool Inventory::findItem(itemManager IM, std::string itemName){
    // needs IM to be finished first
    return false;
}

bool Inventory::checkItemQuant(itemID itemID) {
    auto exists = invContainer.find(itemID);
    int returnQuant = 0;
    if (!(exists == this->invContainer.end() )) {
        returnQuant = exists->second;
    }
    return returnQuant;
}

std::string listItems(itemManager& IM) {
    std::string returnString("");
    std::string itemName("");
    std::string quantStr("");
    int i = 0;
    for (auto item : invContainer) {
        itemName = IM.getItemName(item.first);
        quantStr = to_string(item.second);
        returnString << "<" << itemName << " x " << quantStr << ">, ";
        if (i % 2 == 0){
            returnString << std::endl;
        }
        i++;
    }
    return returnString;
}

bool addItem(itemID item, int quantity) {
    auto exists = invContainer.find(item);
    int curQuant = 0;
    if (!(exists == invContainer.end() )) {
        curQuant = exists.second;
        exists->second += quantity;
    } else (exists == invContainer.end() ){
        if (curSize = maxSize){
            return false;
        }
        else {
            curSize++;
            invContainer.insert( std::make_pair<itemID,int>(item, quantity) );
        }
    }
    exists = invContainer.find(item);
    return (exists->second == (curQuant + quantity));
}

bool removeItem(itemID item, int quantity) {
    auto exists = invContainer.find(item);
    if (!(exists == invContainer.end() )) {
        if (exists.second <= quantity) {
            invContainer.erase(item);
            curSize--;
            return true;
        } else {
            exists.second -= quantity;
            return true;
        }
    } else {
        return false;
    }
}

void alterInvSize(int newSize) {
    maxSize = newSize;
}


