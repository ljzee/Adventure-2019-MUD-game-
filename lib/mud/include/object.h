#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <iostream>

using namespace std;

class Object {
	private:
		int id;
		vector<string> keywords;
		string shortdesc;
		string longdesc;
		//list of extras (can be a list of keywords, a string description)
	public:
		Object();
		string getObjectInfo();
};

#endif
//TODO: complete based on given json file