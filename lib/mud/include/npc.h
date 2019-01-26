//
// Modified by Andre on 1/25/2019.
//

#ifndef NPC_H
#define NPC_H

#include <vector>
#include <string>
#include <iostream>

class Npc {
	private:
		int id;
		std::vector<string> keywords;
		std::string shortdesc;
		std::vector<string> longdesc;
		std::vector<string> description;
	public:
		Npc();

		// Getters
		int getNpcId() const;

		std::string outputNpcInfo();
};

#endif
//TODO: complete based on given json file