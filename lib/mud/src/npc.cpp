//
// Modified by Andre on 1/25/2019.
//

#include "npc.h"

Npc::Npc() {
     this->id = 8800;
     this->keywords.push_back("elf");
     this->keywords.push_back("scout");
     this->shortdesc = "a sylvian elf scout";
     this->longdesc.push_back("A Sylvan Elf scout is offended at your intrusion!");
     this->description.push_back("The Sylvan Elves are a good people, but centuries of subjection to the");
     this->description.push_back("violences and prejudices of other races have made them wary and very");
     this->description.push_back("hostile toward outsiders. However, if you're tough enough, perhaps he'll");
     this->description.push_back("back down. As natives of Mirkwood, they are virtually imposssible to see");
     this->description.push_back("if they don't want to be seen.");
}

int Npc::getNpcId() const { return this->id; }

std::string Npc::outputNpcInfo() {
     std::string strId = std::to_string(this->id);

     std::string concatDesc = "";
     for (auto &portion : this->longdesc) {
          concatDesc +=  portion;
          concatDesc += "\n";
     }
     return strId + concatDesc;
}

