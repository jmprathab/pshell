#pragma once

#include <memory>
#include <list>
#include "Iterator.hpp"

/**
 * Declaration of ListImpl class
 * @tparam T Any specific type
 */

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

    Iterator::ListIterator<T> begin();

    Iterator::ListIterator<T> end();

    Iterator::ConstListIterator<T> begin() const;

    Iterator::ConstListIterator<T> end() const;

private:
    std::list<T> mList;
};


namespace PSTL {

    /**
     * Declaration of List class
     * Follows pimpl idiom
     */

    template<typename T>
    class List {

    public:
        List();

        ~List();

        void insertFront(T element);

        void insertBack(T element);

        void removeFront(T element);

        void removeBack(T element);

        void clear();

        Iterator::ListIterator<T> begin();

        Iterator::ListIterator<T> end();

        Iterator::ConstListIterator<T> begin() const;

        Iterator::ConstListIterator<T> end() const;

    private:
        std::unique_ptr<ListImpl<T> > m_pImpl;
    };
}


/**
 * Implementation of ListImpl class.
 * This class as of now is an adapter for std::list
 * @tparam T Any specific type
 */

template<typename T>
ListImpl<T>::ListImpl() = default;

template<typename T>
ListImpl<T>::~ListImpl() = default;

template<typename T>
void ListImpl<T>::insertFront(T element) {
    mList.push_front(element);
}

template<typename T>
void ListImpl<T>::insertBack(T element) {
    mList.push_back(element);
}

template<typename T>
void ListImpl<T>::removeFront(T element) {
    mList.pop_front(element);
}

template<typename T>
void ListImpl<T>::removeBack(T element) {
    mList.pop_back(element);
}

template<typename T>
void ListImpl<T>::clear() {
    mList.clear();
}

template<typename T>
Iterator::ListIterator<T> ListImpl<T>::begin() {
    return mList.begin();
}

template<typename T>
Iterator::ListIterator<T> ListImpl<T>::end() {
    return mList.end();
}

template<typename T>
Iterator::ConstListIterator<T> ListImpl<T>::begin() const {
    return mList.begin();
}

template<typename T>
Iterator::ConstListIterator<T> ListImpl<T>::end() const {
    return mList.end();
}

/**
 * Definition of List class
 * This class delegates all its work to ListImpl member object
 * @tparam T
 */

template<typename T>
PSTL::List<T>::List() : m_pImpl(new ListImpl<T>()) {

}

template<typename T>
PSTL::List<T>::~List() {
    // No-Op Destructor
}

template<typename T>
void PSTL::List<T>::insertFront(T element) {
    m_pImpl->insertFront(element);
}

template<typename T>
void PSTL::List<T>::insertBack(T element) {
    m_pImpl->insertBack(element);
}

template<typename T>
void PSTL::List<T>::removeFront(T element) {
    m_pImpl->removeFront(element);
}

template<typename T>
void PSTL::List<T>::removeBack(T element) {
    m_pImpl->removeBack(element);
}

template<typename T>
void PSTL::List<T>::clear() {
    m_pImpl->clear();
}

template<typename T>
Iterator::ListIterator<T> PSTL::List<T>::begin() {
    return m_pImpl->begin();
}

template<typename T>
Iterator::ListIterator<T> PSTL::List<T>::end() {
    return m_pImpl->end();
}

template<typename T>
Iterator::ConstListIterator<T> PSTL::List<T>::begin() const {
    return m_pImpl->begin();
}

template<typename T>
Iterator::ConstListIterator<T> PSTL::List<T>::end() const {
    return m_pImpl->end();
}
