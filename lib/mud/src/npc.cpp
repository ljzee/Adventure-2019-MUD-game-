#include "npc.h"

Npc::Npc(int id, vector<std::string> keywords, std::string shortDesc, std::string longDesc, std::string description) :
     id(id),
     keywords(std::move(keywords)),
     shortdesc(shortDesc),
     longdesc(longDesc),
     description(description),
     npcType(Npc::npc),
     health(100),
     currentLocation(),
     isSwapped(false){
}

Npc::Npc(int id, std::string avatarName) :
     id(id),
     keywords(),
     shortdesc(avatarName),
     longdesc(""),
     description(""),
     npcType(Npc::avatar),
     health(100),
     currentLocation(),
     isSwapped(false){
          this->keywords.push_back(this->shortdesc);
}

Npc::~Npc(){}

int Npc::getNpcId() const { return this->id; }

Npc::Type Npc::getNpcType() const { return this->npcType; }

bool Npc::getIsSwapped() const {return this->isSwapped; }

std::unique_ptr<Clonable> Npc::clone() {
     return std::make_unique<Npc>(*this);
}

std::string Npc::outputNpcInfo() {
     std::string strId = std::to_string(this->id);

     std::string concatKeywords = "";
     for (auto &portion : this->keywords) {
          concatKeywords +=  portion + " ";
     }

     return strId + "\n" + concatKeywords + "\n" + longdesc + "\n" + description + "\n";
}

