#include <gtest/gtest.h>
#include "containers/stack.hpp"
#include <vector>
#include <stdexcept>

namespace knife::containers::testing {

TEST(StackTest, InitializationAndEmpty) {
    stack<int> s;
    EXPECT_TRUE(s.is_empty()) << "New stack should be empty";
    EXPECT_EQ(0, s.stack_size()) << "New stack should have size 0";
    EXPECT_EQ(s.begin(), s.end()) << "Begin and end should be equal for empty stack";
}

TEST(StackTest, PushAndSize) {
    stack<int> s;
    s.stack_push(42);
    EXPECT_FALSE(s.is_empty()) << "Stack should not be empty after push";
    EXPECT_EQ(1, s.stack_size()) << "Size should be 1 after one push";
    s.stack_push(10);
    EXPECT_EQ(2, s.stack_size()) << "Size should be 2 after two pushes";
}

TEST(StackTest, PopAndValues) {
    stack<int> s;
    s.stack_push(42);
    s.stack_push(10);
    EXPECT_EQ(10, s.stack_pop()) << "Pop should return top element (10)";
    EXPECT_EQ(1, s.stack_size()) << "Size should decrease after pop";
    EXPECT_EQ(42, s.stack_pop()) << "Pop should return next element (42)";
    EXPECT_TRUE(s.is_empty()) << "Stack should be empty after popping all elements";
}

TEST(StackTest, PopEmptyThrows) {
    stack<int> s;
    EXPECT_THROW(s.stack_pop(), std::runtime_error) << "Popping empty stack should throw";
}

TEST(StackTest, GetValueAtIndex) {
    stack<int> s;
    s.stack_push(30);
    s.stack_push(20);
    s.stack_push(10);
    EXPECT_EQ(10, s.get_val_at_index(0)) << "Index 0 should return top element";
    EXPECT_EQ(20, s.get_val_at_index(1)) << "Index 1 should return second element";
    EXPECT_EQ(30, s.get_val_at_index(2)) << "Index 2 should return third element";
}

TEST(StackTest, GetValueAtInvalidIndexThrows) {
    stack<int> s;
    s.stack_push(42);
    EXPECT_THROW(s.get_val_at_index(-1), std::out_of_range) << "Negative index should throw";
    EXPECT_THROW(s.get_val_at_index(1), std::out_of_range) << "Index beyond size should throw";
    EXPECT_THROW(s.get_val_at_index(10), std::out_of_range) << "Large index should throw";
}

TEST(StackTest, InsertAtIndex) {
    stack<int> s;
    s.stack_push(30);
    s.stack_push(20);
    s.insert_at_index(15, 1); // Stack: 20 -> 15 -> 30
    EXPECT_EQ(3, s.stack_size()) << "Size should increase after insertion";
    EXPECT_EQ(20, s.get_val_at_index(0)) << "Top element should remain 20";
    EXPECT_EQ(15, s.get_val_at_index(1)) << "Inserted element should be at index 1";
    EXPECT_EQ(30, s.get_val_at_index(2)) << "Original bottom element should be at index 2";

    s.insert_at_index(10, 0); // Stack: 10 -> 20 -> 15 -> 30
    EXPECT_EQ(10, s.get_val_at_index(0)) << "Insert at index 0 should act like push";

    s.insert_at_index(40, s.stack_size()); // Stack: 10 -> 20 -> 15 -> 30 -> 40
    EXPECT_EQ(40, s.get_val_at_index(4)) << "Insert at size should append";
}

TEST(StackTest, InsertAtInvalidIndex) {
    stack<int> s;
    s.stack_push(42);
    s.insert_at_index(10, -1); // Should silently return
    s.insert_at_index(10, 2);  // Should silently return
    EXPECT_EQ(1, s.stack_size()) << "Invalid index insertion should not modify stack";
    EXPECT_EQ(42, s.get_val_at_index(0)) << "Stack content should remain unchanged";
}

TEST(StackTest, Iteration) {
    stack<int> s;
    s.stack_push(30);
    s.stack_push(20);
    s.stack_push(10);

    std::vector<int> values;
    for (auto* node = s.begin(); node != s.end(); node = node->next) {
        values.push_back(node->data);
    }

    std::vector<int> expected = {10, 20, 30};
    EXPECT_EQ(expected, values) << "Iteration should yield elements in stack order";
}

TEST(StackTest, EmptyIteration) {
    stack<int> s;
    std::vector<int> values;
    for (auto* node = s.begin(); node != s.end(); node = node->next) {
        values.push_back(node->data);
    }
    EXPECT_TRUE(values.empty()) << "Empty stack iteration should yield no elements";
}

TEST(StackTest, Destructor) {
    {
        stack<int> s;
        s.stack_push(1);
        s.stack_push(2);
        s.stack_push(3);
    }
    SUCCEED() << "Stack destroyed without crashing";
}

} // namespace knife::containers::testing
