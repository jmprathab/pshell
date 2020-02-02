#pragma once

#include <cstddef>

#ifdef _WIN32
#ifdef UTILITIES_MODULE_EXPORT
#define UTILITIES_API __declspec(dllexport)
#else
#define UTILITIES_API __declspec(dllimport)
#endif
#else
#define UTILITIES_API
#endif


namespace Utilities {

    class String {
    public:
        UTILITIES_API String(char *string);

        UTILITIES_API ~String();

        UTILITIES_API size_t length();

    private:
        static size_t getLength(char *data);

        char *mData;
    };
} // namespace Utilities