/**
// Defines the interface for shell implementation
// This is the base class, any new shell should inherit this class
**/
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

#include "interpreter.hpp"

PSH_API class PSH {
public:
    PSH_API PSH(std::unique_ptr<Interpreter> interpreter);

    PSH_API virtual ~PSH();

    PSH_API virtual void initialize();

    PSH_API virtual void execute() = 0;

    PSH_API virtual void terminate();

protected:
    std::unique_ptr<Interpreter> mInterpreter;
};
