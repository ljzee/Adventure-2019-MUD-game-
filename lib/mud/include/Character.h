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

class Character {
	private:
		int id;
		vector<std::string> keywords;
		std::string shortdesc;
		std::string longdesc;
		std::string description;
		Type characterType;
		int health;
		Location currentLocation;
		bool isSwapped;


	public:

        ///Constructors
		Character(int id, vector<std::string> keywords, std::string shortDesc, std::string longDesc, std::string description); //npc constructor
        Character(int id, std::string avatarName); //avatar constructor

        ~Character();

		// Getters
		int getCharacterId() const;
		Type getCharacterType() const;
		bool getIsSwapped()const;

        std::unique_ptr<Clonable> clone() override;
		std::string outputCharacterInfo();
};

#endif
//TODO: complete based on given json file