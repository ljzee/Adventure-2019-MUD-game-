#include "Communicate.h"

namespace commands {
     ///Handles say, tell, yell
        Communicate::Communicate(const networking::Connection connection,
                                           const std::string &commandWord,
                                           const std::string &enteredCommand): Command(connection, commandWord, enteredCommand)
                                           {}

    Communicate::~Communicate() {}

    std::deque<std::pair<uintptr_t, std::string>> Communicate::process(std::unique_ptr<World>& world) {
        std::deque<std::pair<uintptr_t, std::string>> resultMessages;
        std::string characterName = world->getCharacterName(callerConnection);
        if(this->commandWord == "say" || this->commandWord == "yell") {

            std::string returnMessage = characterName + " " + commandWord + "s " + "\"" + enteredCommand + "\"";

            //getRelevantPlayerConnections will get the player connections affected by say or yell command
            auto relevantPlayerConnections = world->getRelevantPlayerConnections(callerConnection, commandWord);
            for(auto connection : relevantPlayerConnections){
                resultMessages.push_back({connection, returnMessage});
            }
            return resultMessages;
        }

        if(this->commandWord == "tell") {
            auto nameAndMessage = SplitInitialWordAndRest(enteredCommand);

            std::string returnMessage = characterName + " tells you " + "\"" + nameAndMessage.second + "\"";

            auto relevantPlayerConnection  = world->getTargetPlayerConnection(callerConnection, nameAndMessage.first);
            if(relevantPlayerConnection.first == World::in_room){
                resultMessages.push_back({relevantPlayerConnection.second, returnMessage});
            }else if(relevantPlayerConnection.first == World::not_in_room){
                resultMessages.push_back({callerConnection.id, nameAndMessage.first + " is not in the room."});
            }
            return resultMessages;
        }

        return resultMessages;
    }
}