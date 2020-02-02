#include "utilities/main/headers/ListImpl.hpp"


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
    mList.pop_back(element);
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

}
