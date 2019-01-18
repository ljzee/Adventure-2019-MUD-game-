//
// Created by Alex on 1/18/2019.
//

#ifndef ROOM_H
#define ROOM_H

class Room {
	private:
		int dummy_objects; // need to change type for later
		int dummy_characters;
		// include in-game objects
		// include characters
		// include other(?)
		// inlucde POINTERS to other rooms; what kind of functions do we need?
		// use an arbitrary new room
	public:
		string name;
		string description;
		void resetRoom();
		int get_dummy_objects;
		int get_dummy_characters;
};