#ifndef PSHELL_ITERATOR_HPP
#define PSHELL_ITERATOR_HPP

#include <list>

class Iterator {
public:
    template<typename T>
    using ListIterator = typename std::list<T>::iterator;

    template<typename T>
    using ConstListIterator = typename std::list<T>::const_iterator;

};

#endif //PSHELL_ITERATOR_HPP
