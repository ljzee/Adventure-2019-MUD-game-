//
// Modified by Andre on 1/25/2019.
//

#include "object.h"


Object::Object(int id, vector<string> keywords, string_view shortdesc, vector<string> longDesc) {
     this->id = id;
     this->keywords = keywords;
     this->shortdesc = shortdesc;
     this->longDesc = longDesc;

     /* Extra dummy struct
     extra ext;
     ext.keywords.push_back("ringmail");
     ext.desc.push_back("This armor is imported from the island of Guam.");
     this->extras.push_back(ext); */
}

// Getters
int Object::getId() const { return this->id; }

std::string Object::getShortDesc() const { return this->shortdesc; }

std::string Object::getObjectInfo() {
     std::string strId = std::to_string(this->id);

     std::string concatDesc = "";
     for (auto &portion : this->longDesc) {
          concatDesc +=  portion;
          concatDesc += "\n";
     }

     return strId + " " + concatDesc;
}

