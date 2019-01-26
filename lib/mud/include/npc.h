#ifndef NPC_H
#define NPC_H

#include <vector>
#include <iostream>

using namespace std;

class Npc {
	private:
		int id;
		vector<string> keywords;
		string shortdesc;
		string longdesc;
		string description;
	public:
		Npc();
		string getNpcInfo();
};

#endif
//TODO: complete based on given json file