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

#include <psh/main/public/psh.hpp>

class SimplePSH : public PSH {
public:
    SimplePSH(std::unique_ptr<Interpreter> interpreter);

    virtual ~SimplePSH();

    virtual void initialize() override;

    virtual void execute() override;

    virtual void terminate() override;
};