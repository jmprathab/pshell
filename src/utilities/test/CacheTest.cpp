#include <utilities/main/public/OrderedCache.hpp>
#include <utilities/main/public/Element.hpp>
#include "gtest/gtest.h"

#include "List.hpp"

#define TEST_SUITE_NAME CacheTest

using namespace PSTL;

TEST(TEST_SUITE_NAME, CacheCreationTest) {
    std::unique_ptr<Cache> cache(new OrderedCache());
    EXPECT_FALSE((cache.get() == nullptr));
}

TEST(TEST_SUITE_NAME, CacheInsertTest) {
    std::unique_ptr<Cache> cache(new OrderedCache());

    /**
     * Creating an inline class to insert into cache
     */
    class DummyElement : public Element {

    };

    CacheElement element(new DummyElement);
    cache->insert(element);

    EXPECT_FALSE((cache.get() == nullptr));
}

TEST(TEST_SUITE_NAME, CacheFrontAccessTest) {
    std::unique_ptr<Cache> cache(new OrderedCache());

    /**
     * Creating an inline class to insert into cache
     */
    class DummyElement : public Element {

    };

    CacheElement element(new DummyElement);
    cache->insert(element);

    auto retrievedFromCache = cache->front();
    EXPECT_EQ(*retrievedFromCache, element);
}

TEST(TEST_SUITE_NAME, CacheBackAccessTest) {
    std::unique_ptr<Cache> cache(new OrderedCache());

    /**
     * Creating an inline class to insert into cache
     */
    class DummyElement : public Element {

    };

    CacheElement element(new DummyElement);
    cache->insert(element);

    auto retrievedFromCache = cache->back();
    EXPECT_EQ(*(--retrievedFromCache), element);
}