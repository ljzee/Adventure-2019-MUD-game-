#include "object.h"

using std::vector;

Object::Object(int id, vector<std::string> keywords, std::string shortDesc, vector<std::string> longDesc) :
     id(id),
     keywords(std::move(keywords)),
     shortDesc(shortDesc),
     longDesc(std::move(longDesc)) {
}

int Object::getId() const { return this->id; }

std::string Object::getShortDesc() const { return this->shortDesc; }

std::string Object::getObjectInfo() {
     std::string strId = std::to_string(this->id);

     std::string concatDesc = "";
     for (auto &portion : this->longDesc) {
          concatDesc +=  portion;
          concatDesc += "\n";
     }

     return strId + " " + concatDesc;
}

