#pragma once
#include "Command.h"

namespace commands {
  STRING_ENUM(SwapCommands, SWAP);
  class CommandSwap : public Command {
  public:
      CommandSwap(const networking::Connection connection, const std::string& commandWord, const std::string& enteredCommand);

      ~CommandSwap();

      std::deque<std::pair<uintptr_t , std::string>> process(std::unique_ptr<World>& world) override;
  };
}
