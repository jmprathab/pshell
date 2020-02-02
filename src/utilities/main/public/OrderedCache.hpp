#ifndef PSHELL_ORDEREDCACHE_HPP
#define PSHELL_ORDEREDCACHE_HPP


#include "Cache.hpp"
#include "List.hpp"

class OrderedCache : public Cache {

private:
    void insertImpl(CacheElement element) override;

    CacheIterator frontImpl() override;

    CacheIterator backImpl() override;

private:
    PSTL::List<CacheElement> mList;
};


#endif //PSHELL_ORDEREDCACHE_HPP
