#include "inventory.h"
#include <iostream>
#include <sstream>

Inventory::Inventory(int invSize)
    : maxSize(invSize)
    , curSize(0){

}

const bool Inventory::checkItem(int itemID) const{
    auto exists = invContainer.find(itemID);
    return (exists == invContainer.end());
}

const bool Inventory::checkItemQuant(itemID itemID) const{
    auto exists = invContainer.find(itemID);
    int returnQuant = 0;
    if (!(exists == this->invContainer.end() )) {
        returnQuant = exists->second;
    }
    return returnQuant;
}

const std::string Inventory::listItems(itemManager& IM) const{
    std::string itemName("");
    std::string quantStr("");
    std::ostringstream os;
    int i = 0;
    for (auto item : invContainer) {
        auto itemReference = IM.itemLookup(item.first);
        auto itemName = itemReference->getName();
        quantStr = "" + item.second;
        os << "<" << itemName << " x " << quantStr << ">, ";
        if (i % 2 == 0){
            os << std::endl;
        }
        i++;
    }
    return os.str();
}

bool Inventory::addItem(itemID item, int quantity) {
    auto exists = invContainer.find(item);
    int curQuant = 0;
    if (!(exists == invContainer.end())) {
        curQuant = exists->second;
        exists->second += quantity;
    } else if (exists == invContainer.end()){
        if (curSize = maxSize){
            return false;
        }
        else {
            curSize++;
            invContainer.insert(std::make_pair<itemID,int>(item, quantity));
        }
    }
    exists = invContainer.find(item);
    return (exists->second == (curQuant + quantity));
}

const bool Inventory::removeItem(itemID item, int quantity) const{
    auto exists = invContainer.find(item);
    if (!(exists == invContainer.end() )) {
        if (exists->second <= quantity) {
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

void Inventory::alterInvSize(int newSize) {
    maxSize = newSize;
}