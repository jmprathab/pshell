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

#include <string>

class Command {
public:
    PSH_API Command(std::string command);

    PSH_API std::string getCommand();

private:
    std::string mCommand;
};