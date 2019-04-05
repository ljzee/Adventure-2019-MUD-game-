#include "Character.h"


Character::Character(int id, vector<std::string> keywords, std::string shortDesc, std::string longDesc, std::string description) :
     id(id),
     keywords(std::move(keywords)),
     shortdesc(shortDesc),
     longdesc(longDesc),
     description(description),
     characterType(Character::nonplayer),
     health(100),
     currentLocation(-1),
     isSwapped(false),
     isPlayer(false)
     {
}

Character::Character(int id, std::string avatarName) :
     id(id),
     keywords(),
     shortdesc(avatarName),
     longdesc(""),
     description(""),
     characterType(Character::player),
     health(100),
     currentLocation(1),
     isSwapped(false),
     isPlayer(true)
     {
          this->keywords.push_back(this->shortdesc);
}

Character::~Character(){}

void Character::updateLocation(int roomId){ this->currentLocation = roomId; }

int Character::getId() const { return this->id; }

std::string Character::getShortDesc() const { return this->shortdesc; }

Character::Type Character::getType() const { return this->characterType; }

bool Character::getIsSwapped() const {return this->isSwapped; }

bool Character::isControlledByPlayer() const {return this->isPlayer; }

int Character::getLocation() const {return this->currentLocation; }

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

