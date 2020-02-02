#define PSH_MODULE_EXPORT

#include "command.hpp"

Command::Command(std::string input) {
    mCommand = input;
}

std::string Command::getCommand() {
    return mCommand;
}