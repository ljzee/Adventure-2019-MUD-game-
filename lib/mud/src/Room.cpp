//
// Created by Alex on 1/18/2019.
//

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

//Will be read in from JSON, so dummy values for now
Room::Room() {

	this->dummy_objects = 1;
	this->dummy_characters = 1;
	this->ID = 0000;
	this->name = "name";
	this->desc = "desc";

}

void room::resetRoom() {
	int arbitrary_limit = 100;
	dummy_characters = rand() % arbitrary_limit;
	dummy_objects = rand() % arbitrary_limit;
}

int room::get_dummy_characters() {
	return dummy_characters;
}

int room::get_dummy_objects() {
	return dummy_objects;
}

//Andrea's getters
int Room::getID() {

	return this->ID;

}

std::string Room::getName() {

	return this->name;

}
std::string Room::getDesc() {

	return this->desc;

}

// NOTES FOR SEVA:
// Isee the google doc again