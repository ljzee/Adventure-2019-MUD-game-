#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <string>
#include <string_view>

using namespace std;

struct extra {
	vector<string> keywords, desc;
};

class Object {
	private:
		int id;
		vector<string> keywords;
		string shortdesc;
		vector<string> longDesc;
		vector<extra> extras;
	public:
		Object(int id, vector<string> keywords, string_view shortdesc, vector<string> longdesc);
		int getId() const;
		string getShortDesc() const;
		string getObjectInfo();
};

#endif
//TODO: complete based on given json file