#ifndef RESET_H
#define RESET_H

class Reset {
	private:
		std::string action;
		int id;
		int limit;
		int room;
		int slot;
		std::string state;
	public:

};


// Simplicity -> consider using a  struct maybe?
// Then move struct into area.h?
struct Reset {
	std::string action;
	int id;
	int limit;
	int room;
	int slot;
	std::string state;
};

#endif
//TODO: complete based on given json file