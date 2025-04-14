#include <gtest/gtest.h>
#include "../../knife/containers/doubly_linked_list.hpp"

TEST(PushFrontTest, BasicAssertions) {
    knife::list<int> list;
    list.push_front(10);
    list.push_back(20);
    list.push_front(5);

    list.push_front(100);
    EXPECT_EQ(list.front(), 100);
}

TEST(PushBackTest, BasicAssertions) {
    knife::list<int> list;
    list.push_front(10);
    list.push_back(20);
    list.push_front(5);

    list.push_back(30);
    EXPECT_EQ(list.at(3), 30);
}

TEST(FrontTest, BasicAssertions) {
    knife::list<int> list;
    list.push_front(10);
    list.push_back(20);
    list.push_front(5);

    EXPECT_EQ(list.front(), 5);
}

TEST(RemoveFrontTest, BasicAssertions) {
    knife::list<int> list;
    list.push_front(10);
    list.push_back(20);
    list.push_front(5);

    list.remove_front();
    EXPECT_EQ(list.front(), 10);
}

TEST(PopBackTest, BasicAssertions) {
    knife::list<int> list;
    list.push_front(10);
    list.push_back(20);
    list.push_front(5);

    list.pop_back();
    EXPECT_EQ(list.at(1), 10);
}

TEST(AtTest, BasicAssertions) {
    knife::list<int> list;
    list.push_front(10);
    list.push_back(20);
    list.push_front(5);

    EXPECT_EQ(list.at(0), 5);
    EXPECT_EQ(list.at(1), 10);
    EXPECT_EQ(list.at(2), 20);
}

TEST(PopAtTest, BasicAssertions) {
    knife::list<int> list;
    list.push_front(10);
    list.push_front(5);
    list.push_front(15);

    list.pop_at(0);
    EXPECT_EQ(list.at(0), 5);
    EXPECT_EQ(list.at(1), 10);

    EXPECT_THROW(list.at(-10), std::out_of_range);
}

TEST(InsertTest, BasicAssertions) {
    knife::list<int> list;
    list.push_front(10);
    list.push_back(20);
    list.push_front(5);

    list.insert(15, 1);
    EXPECT_EQ(list.at(1), 15);
}

TEST(RemoveFromEmptyListTest, BasicAssertions) {
    knife::list<int> list;

    EXPECT_THROW(list.remove_front(), std::runtime_error);
}

TEST(PopBackFromEmptyListTest, BasicAssertions) {
    knife::list<int> list;

    EXPECT_THROW(list.pop_back(), std::runtime_error);
}

TEST(InvalidIndexTest, BasicAssertions) {
    knife::list<int> list;
    list.push_front(10);
    list.push_back(20);
    list.push_front(5);

    EXPECT_THROW(list.at(5), std::out_of_range);
}
