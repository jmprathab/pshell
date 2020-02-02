#include <utilities/main/public/Element.hpp>
#include "Cache.hpp"

void Cache::insert(const CacheElement &element) {
    insertImpl(element);
}

CacheIterator Cache::front() {
    return frontImpl();
}

CacheIterator Cache::back() {
    return backImpl();
}
