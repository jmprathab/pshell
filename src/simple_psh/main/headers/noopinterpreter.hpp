#pragma once

#ifdef _WIN32
#ifdef SIMPLEPSH_MODULE_EXPORT
#define SIMPLEPSH_API __declspec(dllexport)
#else
#define SIMPLEPSH_API __declspec(dllimport)
#endif
#else
#define SIMPLEPSH_API
#endif

#include <psh/main/public/interpreter.hpp>

class NoOpInterpreter : public Interpreter {
public:
    NoOpInterpreter();

    ~NoOpInterpreter();

    virtual void interpret(std::unique_ptr<Command> command) override;
};