#ifndef PSHELL_CACHE_HPP
#define PSHELL_CACHE_HPP

#include <memory>
#include "Iterator.hpp"

class Element;

/**
 * Cache class is used to store Elements
 * Choice of eviction strategy is vested within each implementation of cache.
 * Follows NVPI idiom
 */

using CacheElement = typename std::shared_ptr<Element>;
using CacheIterator = typename Iterator::ConstListIterator<CacheElement>;

class Cache {

public:
    void insert(const CacheElement &element);
    CacheIterator front();
    CacheIterator back();

private:
    virtual void insertImpl(CacheElement element) = 0;

    virtual CacheIterator frontImpl() = 0;
    virtual CacheIterator backImpl() = 0;
};

#endif //PSHELL_CACHE_HPP
