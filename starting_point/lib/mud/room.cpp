//
// Created by Alex on 1/18/2019.
//

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

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

// NOTES FOR SEVA:
// Isee the google doc again