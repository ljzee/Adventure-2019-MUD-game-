//
// Created by Alex on 1/18/2019.
//

//
// Modified by Andrea on 1/24/2019.
//

#ifndef ADVENTURE2019_ROOM_H
#define ADVENTURE2019_ROOM_H

#include <string>

// Using JSON file's ROOM object
//Ex: "id": 8800,
//      "name": "Entrance to Mirkwood",
//      "desc": [
//        "You have entered the quasi-magical Elven forest of Mirkwood, populated by",
//        "Sylvan Elves and their mysterious allies. Strangers are frowned upon here,",
//        "so be on your guard. It is rumored that many different races of Elves",
//        "actually inhabit this forest, in various parts and sometimes they are",
//        "carefully hidden, away from the prying eyes of strangers.",
//        "",
//        "There is a sign tacked to a tree nearby."
//      ],
//      "doors": [
//        {
//          "dir": "north",
//          "desc": [],
//          "keywords": [],
//          "to": 8801
//        },
//        {
//          "dir": "south",
//          "desc": [],
//          "keywords": [],
//          "to": 8855
//        }
//      ],
//      "extended_descriptions": [
//        {
//          "keywords": [
//            "sign"
//          ],
//          "desc": [
//            "This area serves as a connector for many areas with an Elven or Faerie",
//            "flavour, favored areas of the Immortal Yaegar. Tread carefully, and remember",
//            "to keep track of where you have been.",
//            "",
//            "--Yaegar"
//          ]
//        }
//      ]
//    },
class Room {
	private:

		//Alex's stuff - idk what these are, exactly?
		int dummy_objects; // need to change type for later
		int dummy_characters;
		// include in-game objects
		// include characters
		// include other(?)
		// inlucde POINTERS to other rooms; what kind of functions do we need?
		// use an arbitrary new room

		//Andrea's stuff
		int ID;
		std::string name;
		std::string desc;
		//will need a DOOR object once we have a door class
		//also add this extended descriptions field from JSON?? or maybe we don' care idk

	public:

		//Alex's
		void resetRoom();
		int get_dummy_objects;
		int get_dummy_characters;

		//Andrea's
		Room();
		int getID();
		std::string getName();
		std::string getDesc();
};

#endif //ADVENTURE2019_ROOM_H