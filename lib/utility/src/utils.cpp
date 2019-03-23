//
// Created by Dev on 2019-03-11.
//

#include "utils.h"

std::pair<std::string, std::string> SplitInitialWordAndRest(std::string stringToTrim){

    boost::trim_if(stringToTrim, boost::is_any_of(" "));
    std::string initialWord = stringToTrim.substr(0, stringToTrim.find(' '));
    std::string rest;
    if(stringToTrim.find(' ') == std::string::npos){
        rest = "";
    }else {
        rest = stringToTrim.substr(stringToTrim.find(' '), stringToTrim.size() - 1);
        boost::trim_if(rest, boost::is_any_of(" "));
    }
    return {initialWord, rest};

}