#pragma once

#ifdef _WIN32
#ifdef UTILITIES_MODULE_EXPORT
#define UTILITIES_API __declspec(dllexport)
#else
#define UTILITIES_API __declspec(dllimport)
#endif
#else
#define UTILITIES_API
#endif

#include <memory>

namespace PSTL {

    /**
     * Adapter to std::list
     * Follows pimpl idiom
     */

    template<typename T>
    class List {

        template<typename>
        class ListImpl;

    public:
        UTILITIES_API List();

        UTILITIES_API ~List();

        UTILITIES_API void insertFront(T element);

        UTILITIES_API void insertBack(T element);

        UTILITIES_API void removeFront(T element);

        UTILITIES_API void removeBack(T element);

        UTILITIES_API void clear();

    private:
        std::unique_ptr<ListImpl<T> > m_pImpl;
    };
}

