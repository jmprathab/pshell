#include "gtest/gtest.h"

#include "List.hpp"

using namespace PSTL;

#define TEST_SUITE_NAME ListTest

TEST(TEST_SUITE_NAME, ListCreationTest) {
    std::unique_ptr<List<int>> list(new List<int>());
    EXPECT_FALSE((list.get() == nullptr));
}

TEST(TEST_SUITE_NAME, ListInsertionTest) {
    std::unique_ptr<List<int>> list(new List<int>());
    list->insertFront(1);
    EXPECT_FALSE((list == nullptr));
}