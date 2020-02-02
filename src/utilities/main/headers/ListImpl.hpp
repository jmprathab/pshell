#pragma once

#include <list>

template<typename T>
class ListImpl {
public:
    ListImpl();

    ~ListImpl();

    void insertFront(T element);

    void insertBack(T element);

    void removeFront(T element);

    void removeBack(T element);

    void clear();

private:
    std::list<T> mList;
};
