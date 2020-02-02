#include "OrderedCache.hpp"

void OrderedCache::insertImpl(const CacheElement element) {
    mList.insertBack(element);
}

CacheIterator OrderedCache::frontImpl() {
    return mList.begin();
}

CacheIterator OrderedCache::backImpl() {
    return mList.end();
}
