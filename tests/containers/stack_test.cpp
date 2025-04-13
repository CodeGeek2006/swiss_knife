#include <gtest/gtest.h>
#include "containers/stack.hpp"
#include <vector>
#include <stdexcept>

namespace knife::containers::testing {

TEST(StackTest, InitializationAndEmpty) {
    stack<int> s;
    EXPECT_TRUE(s.empty()) << "New stack should be empty";
    EXPECT_EQ(0, s.size()) << "New stack should have size 0";
    EXPECT_EQ(s.begin(), s.end()) << "Begin and end should be equal for an empty stack";
}

TEST(StackTest, PushAndSize) {
    stack<int> s;
    s.push(42);
    EXPECT_FALSE(s.empty()) << "Stack should not be empty after push";
    EXPECT_EQ(1, s.size()) << "Size should be 1 after one push";
    s.push(10);
    EXPECT_EQ(2, s.size()) << "Size should be 2 after two pushes";
}

TEST(StackTest, PopAndValues) {
    stack<int> s;
    s.push(42);
    s.push(10);
    EXPECT_EQ(10, s.top()) << "Pop should return top element (10)";
    s.pop();
    EXPECT_EQ(1, s.size()) << "Size should decrease after pop";
    EXPECT_EQ(42, s.top()) << "Pop should return next element (42)";
    s.pop();
    EXPECT_TRUE(s.empty()) << "Stack should be empty after popping all elements";
}

TEST(StackTest, PopEmptyThrows) {
    stack<int> s;
    EXPECT_THROW(s.pop(), std::runtime_error) << "Popping empty stack should throw error";
}

TEST(StackTest, GetValueAtIndex) {
    stack<int> s;
    s.push(30);
    s.push(20);
    s.push(10);
    EXPECT_EQ(10, s.at(0)) << "Index 0 should return top element";
    EXPECT_EQ(20, s.at(1)) << "Index 1 should return second element";
    EXPECT_EQ(30, s.at(2)) << "Index 2 should return third element";
}

TEST(StackTest, GetValueAtInvalidIndexThrows) {
    stack<int> s;
    s.push(42);
    EXPECT_THROW(s.at(-1), std::out_of_range) << "Negative index should throw";
    EXPECT_THROW(s.at(1), std::out_of_range) << "Index beyond size should throw";
    EXPECT_THROW(s.at(10), std::out_of_range) << "Large index should throw";
}

TEST(StackTest, InsertAtIndex) {
    stack<int> s;
    s.push(30);
    s.push(20);
    s.insert(15, 1); // Stack: 20 -> 15 -> 30
    EXPECT_EQ(3, s.size()) << "Size should increase after insertion";
    EXPECT_EQ(20, s.at(0)) << "Top element should remain 20";
    EXPECT_EQ(15, s.at(1)) << "Inserted element should be at index 1";
    EXPECT_EQ(30, s.at(2)) << "Original bottom element should be at index 2";

    s.insert(10, 0); // Stack: 10 -> 20 -> 15 -> 30
    EXPECT_EQ(10, s.at(0)) << "Insert at index 0 should act like push";

    s.insert(40, s.size()); // Stack: 10 -> 20 -> 15 -> 30 -> 40
    EXPECT_EQ(40, s.at(4)) << "Insert at size should append";
}

TEST(StackTest, InsertAtInvalidIndex) {
    stack<int> s;
    s.push(42);
    s.insert(10, -1); // Should silently return
    s.insert(10, 2);  // Should silently return
    EXPECT_EQ(1, s.size()) << "Invalid index insertion should not modify stack";
    EXPECT_EQ(42, s.at(0)) << "Stack content should remain unchanged";
}

TEST(StackTest, Iteration) {
    stack<int> s;
    s.push(30);
    s.push(20);
    s.push(10);

    std::vector<int> values;
    for (auto* node = s.begin(); node != s.end(); node = node->next) {
        values.push_back(node->val);
    }

    std::vector<int> expected = {10, 20, 30};
    EXPECT_EQ(expected, values) << "Iteration should yield elements in stack order";
}

TEST(StackTest, EmptyIteration) {
    stack<int> s;
    std::vector<int> values;
    for (auto* node = s.begin(); node != s.end(); node = node->next) {
        values.push_back(node->val);
    }
    EXPECT_TRUE(values.empty()) << "Empty stack iteration should yield no elements";
}

TEST(StackTest, Destructor) {
    {
        stack<int> s;
        s.push(1);
        s.push(2);
        s.push(3);
    }
    SUCCEED() << "Stack destroyed without crashing";
}

} // namespace knife::containers::testing
