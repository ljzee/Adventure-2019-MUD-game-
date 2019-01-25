#include <iostream>
#include <vector>
#include "object.h"

using namespace std;

Object::Object() {
     id = 8800;
     keywords.push_back("pool");
     shortdesc = "a pool";
     longdesc = "A pool of crystal-clear water fills this clearing.";

}

string Object::getObjectInfo() {
     return to_string(id) + " " + longdesc + "\n";
}

