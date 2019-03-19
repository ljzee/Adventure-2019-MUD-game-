//
// Created by Andrew on 2019-02-19.
//

#ifndef ADVENTURE2019_ITEMMANAGER_H
#define ADVENTURE2019_ITEMMANAGER_H

#include "item.h"

namespace item;

typedef int itemID;

class itemManager {
public:
    void loadFromFile();
    void writeToJSON();

    //define item methods per class
    bool defineItem(int itemID, itemType itemClass, );
    bool defineItem()

    itemID nextID(){return itemMap.size()};
    baseItem* findItem(itemID itemID);
    const std::string getItemName(itemID) const;

private:
    std::map<itemID, baseItem*> itemMap;
};

#endif //ADVENTURE2019_ITEMMANAGER_H
