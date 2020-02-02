#define UTILITIES_MODULE_EXPORT

#include "List.hpp"
#include <memory>

template<typename T>
PSTL::List<T>::List() : m_pImpl(std::make_unique<ListImpl>(new ListImpl())) {

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
