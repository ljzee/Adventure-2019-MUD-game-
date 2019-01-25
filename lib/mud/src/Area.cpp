//
// Created by Andrea Renney on 2019-01-24.
//

#include "../include/Area.h"
#include <string>

//The name field will need to be read in from the JSON file
//Just a dummy name for now
Area::Area() {

    this->dummy_name = "DUMMY";

}

std::string Area::get_dummy_name() {

    return this->dummy_name;

}
