#define UTILITIES_MODULE_EXPORT

#include "String.hpp"

#include <cmath>
#include <cstring>

#define STRING_BUFFER_LENGTH 8

Utilities::String::String(char *sData) {
    if (sData == nullptr) {
        mData = nullptr;
        return;
    }
    size_t nLengthToAllocate = STRING_BUFFER_LENGTH;
    size_t nSrcLength = getLength(sData);
    if (nSrcLength >= STRING_BUFFER_LENGTH) {
        size_t factor = (size_t) ceil(nSrcLength / STRING_BUFFER_LENGTH);
        nLengthToAllocate = factor * STRING_BUFFER_LENGTH;
    }

    char *buffer = new char[nLengthToAllocate];
    strcpy(buffer, sData);
    mData = buffer;
}

Utilities::String::~String() {
    delete[] mData;
    mData = nullptr;
}

size_t Utilities::String::length() {
    return getLength(mData);
}

size_t Utilities::String::getLength(char *string) {
    if (nullptr == string)
        return 0;
    size_t nLength = 0;
    char cCurrent = string[nLength];
    while (cCurrent != '\0') {
        nLength++;
        cCurrent = string[nLength];
    }
    return nLength;
}