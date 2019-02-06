#include "object.h"


Object::Object(int id, vector<string> keywords, string_view shortdesc, vector<string> longDesc) {
     this->id = id;
     this->keywords = keywords;
     this->shortdesc = shortdesc;
     this->longDesc = longDesc;
}

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

