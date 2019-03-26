//
// Created by Andrew on 2019-02-19.
//

#include "json.hpp"
#include <vector>
#include <string>
#include <utility>

#include "itemManager.h"

using json = nlohmann::json;

bool itemManager::addItem(std::unique_ptr<baseItem> item){
    itemMap.insert({itemMap.size(), item});
}

bool itemManager::removeItem(itemID item){
    itemMap.erase(item);
}

std::unique_ptr<baseItem> itemLookup(itemID id) {
    auto exists = itemMap.find(id);
    if (!(exists == itemMap.end() )){
        return exists->second;
    } else {
        return itemMap.begin()->second;
    }
}




