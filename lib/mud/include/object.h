//
// Modified by Andre on 1/25/2019.
//

#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <string>

struct extra {
	std::vector<string> keywords, desc;
};

class Object {
	private:
		int id;
		std::vector<string> keywords;
		std::string shortdesc;
		std::vector<string> longDesc;
		std::vector<extra> extras;
	public:
		Object();
		int getId() const;
		std::string getShortDesc() const;
		std::string getObjectInfo();
};

#endif
//TODO: complete based on given json file