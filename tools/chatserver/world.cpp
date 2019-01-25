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

    if(msg == ""){
        cout << id << " says: " << " " << endl;
    } else{

        tokenizer<> tok(msg);
        tokenizer<>::iterator beg = tok.begin();

        string cmd = *beg;
        string message = "";

        for(beg = ++beg; beg!=tok.end(); ++beg){
                message += " " + *beg;
            }

        if(boost::iequals(cmd, "yell")) {
            cout << id << " yells:" << message << endl;
        } else if(boost::iequals(cmd, "tell")) {
            //replace 'someone' with 2nd users id once users are setup
            cout << id << " tells: " << "(username) " << message << endl;
        } else {
            cout << id << " says: " << cmd << message << endl;
        }

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

