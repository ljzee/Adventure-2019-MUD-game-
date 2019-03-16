#include "Character.h"


Character::Character(int id, vector<std::string> keywords, std::string shortDesc, std::string longDesc, std::string description) :
     id(id),
     keywords(std::move(keywords)),
     shortdesc(shortDesc),
     longdesc(longDesc),
     description(description),
     characterType(Character::nonplayer),
     health(100),
     currentLocation(),
     isSwapped(false){
}

Character::Character(int id, std::string avatarName) :
     id(id),
     keywords(),
     shortdesc(avatarName),
     longdesc(""),
     description(""),
     characterType(Character::player),
     health(100),
     currentLocation(),
     isSwapped(false){
          this->keywords.push_back(this->shortdesc);
}

Character::~Character(){}

int Character::getCharacterId() const { return this->id; }

Character::Type Character::getCharacterType() const { return this->npcType; }

bool Character::getIsSwapped() const {return this->isSwapped; }

std::unique_ptr<Clonable> Character::clone() {
     return std::make_unique<Character>(*this);
}

std::string Character::outputCharacterInfo() {
     std::string strId = std::to_string(this->id);

     std::string concatKeywords = "";
     for (auto &portion : this->keywords) {
          concatKeywords +=  portion + " ";
     }

     return strId + "\n" + concatKeywords + "\n" + longdesc + "\n" + description + "\n";
}

