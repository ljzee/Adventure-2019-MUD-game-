#ifndef NPC_H
#define NPC_H

#include <vector>
#include <string>
#include <iostream>
#include <string_view>

using namespace std;

class Npc {
	private:
		int id;
		vector<string> keywords;
		string shortdesc;
		vector<string> longdesc;
		vector<string> description;
	public:
		Npc(int id, vector<string> keywords, string_view shortdesc, vector<string> longdesc, vector<string> description);

		// Getters
		int getNpcId() const;

		string outputNpcInfo();
};

#endif
//TODO: complete based on given json file