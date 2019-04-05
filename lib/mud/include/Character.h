#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <iostream>
#include <string>

#include "clonable.h"

using std::vector;

struct Location {
    std::string areaName;
    int roomId;

    bool
    operator==(Location other) const {
        return ((areaName == other.areaName)&&(roomId == other.roomId));
    }
};

class Character : public Clonable{

    enum Type{
        nonplayer = 0, player
    };

	private:
		int id;
		vector<std::string> keywords;
		std::string shortdesc;
		std::string longdesc;
		std::string description;
		Type characterType;
		int health;
		int currentLocation;
		//Location currentLocation;
		bool isSwapped;
		bool isPlayer;


	public:

        ///Constructors
		Character(int id, vector<std::string> keywords, std::string shortDesc, std::string longDesc, std::string description); //npc constructor
        Character(int id, std::string avatarName); //avatar constructor

        ~Character();

        //Setters
        void updateLocation(int roomId);

		// Getters
		int getId() const;
		std::string getShortDesc() const;
		Type getType() const;
		int getLocation() const;
	    bool getIsSwapped() const;
	    bool isControlledByPlayer() const;

        std::unique_ptr<Clonable> clone() override;
		std::string outputCharacterInfo();
};

#endif
//TODO: complete based on given json file