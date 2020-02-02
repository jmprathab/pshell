#pragma once

#ifdef _WIN32
#ifdef PSH_MODULE_EXPORT
#define PSH_API __declspec(dllexport)
#else
#define PSH_API __declspec(dllimport)
#endif
#else
#define PSH_API
#endif

#include <memory>

#include "command.hpp"

class Interpreter {
public:
    PSH_API Interpreter();

    PSH_API virtual ~Interpreter();

    PSH_API virtual void interpret(std::unique_ptr<Command> command) = 0;
};