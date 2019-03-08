#include "object.h"

using std::vector;

Object::Object(int id, vector<std::string> keywords, std::string shortDesc, std::string longDesc) :
     id(id),
     keywords(std::move(keywords)),
     shortDesc(shortDesc),
     longDesc(longDesc) {
}

int Object::getId() const { return this->id; }

std::string Object::getShortDesc() const { return this->shortDesc; }

std::string Object::getObjectInfo() {
     std::string strId = std::to_string(this->id);

     std::string concatKeywords = "";
     for (auto &portion : this->keywords) {
          concatKeywords +=  portion + " ";

     }

     return strId + "\n" + concatKeywords + "\n" + longDesc + "\n";
}

