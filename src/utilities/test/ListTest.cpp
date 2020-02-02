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

TEST(TEST_SUITE_NAME, ListForwardIterationTest) {
    std::unique_ptr<List<int>> list(new List<int>());

    list->insertBack(1);
    list->insertBack(2);
    list->insertBack(3);

    auto beginning{list->begin()};
    auto end{list->end()};

    EXPECT_EQ(*beginning, 1);
    EXPECT_EQ(*(++beginning), 2);
    EXPECT_EQ(*(++beginning), 3);
    EXPECT_EQ(++beginning, end);
}

TEST(TEST_SUITE_NAME, ListBackwardIterationTest) {
    std::unique_ptr<List<int>> list(new List<int>());

    list->insertBack(1);
    list->insertBack(2);
    list->insertBack(3);

    auto beginning{list->begin()};
    auto end{list->end()};

    EXPECT_EQ(*(--end), 3);
    EXPECT_EQ(*(--end), 2);
    EXPECT_EQ(*(--end), 1);
    EXPECT_EQ(end, beginning);
}

TEST(TEST_SUITE_NAME, ListIterationRangeBasedForLoop) {
    std::unique_ptr<List<int>> list(new List<int>());

    list->insertBack(1);
    list->insertBack(2);
    list->insertBack(3);

    int val{1};
    for (auto &item : *list) {
        EXPECT_EQ(val, item);
        val++;
    }
}