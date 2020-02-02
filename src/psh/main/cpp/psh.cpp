#define PSH_MODULE_EXPORT

#include "psh.hpp"

#include <iostream>

PSH::PSH(std::unique_ptr<Interpreter> interpreter) {
    mInterpreter = std::move(interpreter);
}

PSH::~PSH() {
    // Nothing to do here
}

void PSH::initialize() {
    std::cout << "PSH : Initializing\n";
}

void PSH::terminate() {
    std::cout << "PSH : Terminating\n";
}