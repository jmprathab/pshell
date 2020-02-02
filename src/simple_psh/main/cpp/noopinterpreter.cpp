#define SIMPLEPSH_MODULE_EXPORT

#include "noopinterpreter.hpp"

#include <iostream>

NoOpInterpreter::NoOpInterpreter() {
    // Nothing to do here
}

NoOpInterpreter::~NoOpInterpreter() {
    // Nothing to do here
}

void NoOpInterpreter::interpret(std::unique_ptr<Command> userCommand) {
    std::cout << "Interpreting command : " << userCommand->getCommand() << "\n";
}