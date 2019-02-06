#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <string>
using std::vector;

struct extra {
	vector<std::string> keywords, desc;
};

class Object {
	private:
		int id;
		vector<std::string> keywords;
		std::string shortDesc;
		vector<std::string> longDesc;
		vector<extra> extras;
	public:
		Object(int id, vector<std::string> keywords, std::string shortDesc, vector<std::string> longDesc);
		int getId() const;
		std::string getShortDesc() const;
		std::string getObjectInfo();
};

#endif
//TODO: complete based on given json file