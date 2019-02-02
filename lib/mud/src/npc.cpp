//
// Modified by Adrien on 2/2/2019.
//

#include "npc.h"

using namespace std;

Npc::Npc(int id, vector<string> keywords, string_view shortdesc, vector<string> longdesc, vector<string> description){
     this->id = id;
     this->keywords = keywords;
     this->shortdesc = shortdesc;
     this->longdesc = longdesc;
     this->description = description;
}

int Npc::getNpcId() const { return this->id; }

string Npc::outputNpcInfo() {
     string strId = std::to_string(this->id);

     string concatDesc = " ";
     for (auto &portion : this->longdesc) {
          concatDesc +=  portion;
          concatDesc += "\n";
     }
     return strId + concatDesc;
}

