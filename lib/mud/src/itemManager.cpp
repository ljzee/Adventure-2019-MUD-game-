//
// Created by Andrew on 2019-02-19.
//

#include "json.hpp"
#include <vector>
#include <string>
#include <utility>

#include "itemManager.h"

using json = nlohmann::json;

void itemManager::addItem(std::unique_ptr<baseItem> item) {
    itemMap.insert({itemMap.size(), std::move(item)});
}

void itemManager::removeItem(itemID item){
    itemMap.erase(item);
}

const std::unique_ptr<baseItem> itemManager::itemLookup(itemID id) const{
    auto exists = itemMap.find(id);
    if (!(exists == itemMap.end() )){
        return exists->second.get();
    } else {
        return itemMap.begin()->second.get();
    }
}




