//
// Modified by Andre on 1/25/2019.
//

#include "object.h"

// These values should be read in from the JSON file so just dummy values for now
Object::Object() {
     this->id = 10500;
     this->keywords.push_back("chamorro");
     this->keywords.push_back("ringmail");
     this->shortdesc = "chamorro ringmail";
     this->longDesc.push_back("A bunch of rings sewn together with taotamoa bark is on the ground.");

     // Extra dummy struct
     extra ext;
     ext.keywords.push_back("ringmail");
     ext.desc.push_back("This armor is imported from the island of Guam.");
     this->extras.push_back(ext);
}

// Getters
int Object::getId() const { return this->id; }

std::string Object::getShortDesc() const { return this->shortdesc; }

std::string Object::getObjectInfo() {
     std::string strId = to_string(this->id);

     std::string concatDesc = "";
     for (auto &portion : this->longDesc) {
          concatDesc +=  portion;
          concatDesc += "\n";
     }

     return strId + " " + concatDesc + "\n";
}

