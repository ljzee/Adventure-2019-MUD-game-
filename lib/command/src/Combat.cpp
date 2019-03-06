#include "Combat.h"

namespace commands {
    std::vector<std::string> const CommandCombat::values = boost::assign::list_of("attack")("kill");
    CommandCombat::CommandCombat(const networking::Connection connection,
                                 const std::string &commandWord,
                                 const std::string &enteredCommand): Command(connection, commandWord, enteredCommand)
                                 {}

    CommandCombat::~CommandCombat(){}

    std::deque<std::pair<uintptr_t , std::string>> CommandCombat::process(std::unique_ptr<World>& world) {
        std::deque<std::pair<uintptr_t, std::string>> resultMessages;

        if(this->commandWord == "attack"){
            std::cout << "calling attack" << std::endl;
            return resultMessages;
        }

        if(this->commandWord == "kill"){
            std::cout << "calling kill" << std::endl;
            return resultMessages;
        }

        return resultMessages;
    }
}