#include "npc.h"

Npc::Npc(int id, vector<std::string> keywords, std::string shortDesc, vector<std::string> longDesc, vector<std::string> description) :
     id(id),
     keywords(std::move(keywords)),
     shortdesc(shortDesc),
     longdesc(std::move(longDesc)),
     description(std::move(description)) {
}

int Npc::getNpcId() const { return this->id; }

std::string Npc::outputNpcInfo() {
     std::string strId = std::to_string(this->id);

     std::string concatDesc = " ";
     for (auto &portion : this->longdesc) {
          concatDesc +=  portion;
          concatDesc += "\n";
     }
     return strId + concatDesc;
}

