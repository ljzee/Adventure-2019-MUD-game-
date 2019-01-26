#include <iostream>
#include <vector>
#include "npc.h"

using namespace std;

Npc::Npc() {
     id = 8800;
     keywords.push_back("elf");
     keywords.push_back("scout");
     shortdesc = "a sylvian elf scout";
     longdesc = "A Sylvan Elf scout is offended at your intrusion!";
     description = "The Sylvan Elves are a good people, but centuries of subjection to the",
             "violences and prejudices of other races have made them wary and very",
             "hostile toward outsiders. However, if you're tough enough, perhaps he'll",
             "back down. As natives of Mirkwood, they are virtually imposssible to see",
             "if they don't want to be seen.";
}

string Npc::getNpcInfo() {
     return to_string(id) + " " + longdesc + "\n";
}

