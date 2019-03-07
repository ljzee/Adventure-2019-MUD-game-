#pragma once
#include "Command.h"

namespace commands {
  class CommandSwap : public Command {
  public:
      static const std::vector<std::string> values;
      CommandSwap(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

      ~CommandSwap();

      std::deque<std::pair<uintptr_t , std::string>> process(std::unique_ptr<World>& world) override;
  };
}
