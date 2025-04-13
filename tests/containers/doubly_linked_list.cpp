#include <gtest/gtest.h>
#include "../../knife/containers/doubly_linked_list.hpp"

class list_test : public ::testing::Test {
protected:
    knife::list<int> list;

    void SetUp() override {
        list.add_front(10);
        list.add_back(20);
        list.add_front(5);
    }
};

TEST_F(list_test, add_front_test) {
    list.add_front(100);
    EXPECT_EQ(list.get_front(), 100);
}

TEST_F(list_test, add_back_test) {
    list.add_back(30);
    EXPECT_EQ(list.get_at(3), 30);
}

TEST_F(list_test, get_front_test) {
    EXPECT_EQ(list.get_front(), 5);
}

TEST_F(list_test, remove_front_test) {
    list.remove_front();
    EXPECT_EQ(list.get_front(), 10);
}

TEST_F(list_test, remove_tail_test) {
    list.remove_tail();
    EXPECT_EQ(list.get_at(1), 10);
}

TEST_F(list_test, get_at_test) {
    EXPECT_EQ(list.get_at(0), 5);
    EXPECT_EQ(list.get_at(1), 10);
    EXPECT_EQ(list.get_at(2), 20);
}

TEST_F(list_test, remove_at_test) {
    list.add_front(5);
    list.add_front(10);
    list.add_front(15);
    list.remove_at(1);
    EXPECT_EQ(list.get_at(0), 15);
    EXPECT_EQ(list.get_at(1), 5);
    EXPECT_THROW(list.get_at(-10), std::out_of_range);
}

TEST_F(list_test, insert_at_test) {
    list.insert_at(15, 1);
    EXPECT_EQ(list.get_at(1), 15);
}

TEST_F(list_test, remove_from_empty_list_test) {
    list.remove_front();
    list.remove_front();
    list.remove_front();
    EXPECT_THROW(list.remove_front(), std::runtime_error);
}

TEST_F(list_test, remove_tail_from_empty_list_test) {
    list.remove_tail();
    list.remove_tail();
    list.remove_tail();
    EXPECT_THROW(list.remove_tail(), std::runtime_error);
}

TEST_F(list_test, invalid_index_test) {
    EXPECT_THROW(list.get_at(5), std::out_of_range);
}


