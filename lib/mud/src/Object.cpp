//
// Created by Andrea Renney on 2019-01-24.
//

#include "../include/Object.h"
#include <vector>
#include <string>

//These values should be read in from the JSON file so just dummy values for now
Object::Object() {

    this->ID = "0000";
    this->keywords = {"key1", "key2"};
    this->shortdesc = "a short description";
    this->longdesc = "a longer description";

    vector<std::string> keywords {"some extra keys"};
    vector<std::string> desc {"some extra description"};

    this->extra = {keywords, desc};

}

//A bunch of getters

int Object::getID() {

    return this->ID;

}

vector<std::string> Object::getKeywords() {

    return this->keywords;

}

std::string Object::getShortDesc() {

    return this->shortdesc;

}

std::string Object::getLongDesc() {

    return this->longdesc;

}

vector<vector<std::string>> Object::getExtra() {

    return this->extra;

}
