#ifndef NPC_H
#define NPC_H

#include <vector>
#include <iostream>
#include <string>

using std::vector;

class Character {
	private:
		int id;
		vector<std::string> keywords;
		std::string shortdesc;
		vector<std::string> longdesc;
		vector<std::string> description;
	public:
		Character(int id, vector<std::string> keywords, std::string shortDesc, vector<std::string> longDesc, vector<std::string> description);

		// Getters
		int getNpcId() const;

		std::string outputNpcInfo();
};

#endif
//TODO: complete based on given json file