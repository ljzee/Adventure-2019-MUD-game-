//
// Created by Adrien on 1/17/2019.
//

#include "world.h"
#include <iostream>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;

void World::getMessageFromServer(std::string msg, uintptr_t id) {
   //std::cout << "This is in the World Class. From client-server: " << msg << std::endl;

    tokenizer<> tok(msg);
    tokenizer<>::iterator beg = tok.begin();

    string cmd = *beg;
    string message = "";

    for(beg = ++beg; beg!=tok.end(); ++beg){
        message += " " + *beg;
    }

//    if(boost::iequals(cmd, "say")) {
//        cout << id << " says:" << message << endl;
//    } else if(boost::iequals(cmd, "yell")) {
//        cout << id << " yells:" << message << endl;
//    } else if(boost::iequals(cmd, "tell")) {
//        cout << id << " tells someone:" << message << endl;
//    } else {
//        cout << id << " entered an invalid command" << endl;
//    }

    if(boost::starts_with(cmd, "yell")) {
        cout << id << " yells:" << message << endl;
    } else if(boost::starts_with(cmd, "tell")) {
        //replace 2nd id with another users id
        cout << id << " tells:" << id << message << endl;
    } else {
        cout << id << " says:" << msg << endl;
    }

}

std::string World::getMotd() {
    cout << "The world sent a message to the user who requested the MOTD" << endl;
    string motd = "Welcome to Babka's World. The world is currently on development.";
    return motd;
}

World::World() {
    cout << "World created. The world is currently empty." << endl;
}

