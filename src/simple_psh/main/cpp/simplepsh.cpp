#define SIMPLEPSH_MODULE_EXPORT

#include "simplepsh.hpp"

#include <iostream>
#include <string>

SimplePSH::SimplePSH(std::unique_ptr<Interpreter> interpreter)
        : PSH(std::move(interpreter)) {
    // Nothing to do here
}

SimplePSH::~SimplePSH() {
    // Nothing to do here
}

void SimplePSH::execute() {
    while (true) {
        std::cout << ">>";
        std::string userInput;
        getline(std::cin, userInput);
        if (0 == userInput.compare("exit")) {
            break;
        }
        std::unique_ptr<Command> userCommand(new Command(userInput));
        mInterpreter->interpret(std::move(userCommand));
    }
}

void SimplePSH::initialize() {
    // Nothing to do here
}

void SimplePSH::terminate() {
    // Nothing to do here
}