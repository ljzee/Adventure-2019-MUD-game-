#ifndef NPC_H
#define NPC_H

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

class Npc : public Clonable{

    enum Type{
        npc = 0, avatar
    };

	private:
		int id;
		vector<std::string> keywords;
		std::string shortdesc;
		std::string longdesc;
		std::string description;
		Type npcType;
		int health;
		Location currentLocation;
		bool isSwapped;


	public:

        ///Constructors
		Npc(int id, vector<std::string> keywords, std::string shortDesc, std::string longDesc, std::string description); //npc constructor
        Npc(int id, std::string avatarName); //avatar constructor

        ~Npc();

		// Getters
		int getNpcId() const;
		Type getNpcType() const;
		bool getIsSwapped()const;

        std::unique_ptr<Clonable> clone() override;
		std::string outputNpcInfo();
};

#endif
//TODO: complete based on given json file