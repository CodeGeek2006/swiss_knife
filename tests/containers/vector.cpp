#include <gtest/gtest.h>
#include "../../knife/knife.hpp"
#include <stdexcept>      // For std::out_of_range
#include <numeric>        // For std::accumulate (if needed in future tests)


// --- Constructors ---
TEST(VectorTest, BasicOperations) {
    std::vector<int> vec;
    knife::vector<int> vec2;
    EXPECT_EQ(vec.size(), vec2.size());


    knife::vector<int> v(5);
    EXPECT_EQ(v.size(), 0);


    knife::vector<int> v2(3, 42);
    EXPECT_EQ(v2.size(), 3);
    EXPECT_EQ(v2[0], 42);
    EXPECT_EQ(v2[1], 42);
    EXPECT_EQ(v2[2], 42);

// --- push_back & pop_back ---
    knife::vector<int> v3;
    v3.push_back(10);
    EXPECT_EQ(v3.size(), 1);
    EXPECT_EQ(v3[0], 10);

    knife::vector<int> v4;
    v4.push_back(100);
    v4.push_back(200);
    v4.pop_back();
    EXPECT_EQ(v4.size(), 1);
    EXPECT_EQ(v4[0], 100);

// --- PopBackToEmpty ---
    knife::vector<int> v5;
    v5.push_back(42);
    v5.pop_back();
    EXPECT_EQ(v5.size(), 0);

// --- PopBackFromEmptyDoesNothing ---
    knife::vector<int> v6;
    EXPECT_NO_THROW(v6.pop_back());
    EXPECT_EQ(v6.size(), 0);
}

// --- resize ---
TEST(VectorTest, Resize) {
    knife::vector<int> v;
    v.push_back(1);
    v.resize(3);
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[1], 0);
    EXPECT_EQ(v[2], 0);

    knife::vector<int> v2;
    v2.push_back(1);
    v2.resize(4, 7);
    EXPECT_EQ(v2.size(), 4);
    EXPECT_EQ(v2[1], 7);
    EXPECT_EQ(v2[3], 7);
}

// --- operator[] ---
TEST(VectorTest, Operator) {
    knife::vector<int> v;
    v.push_back(1);
    EXPECT_THROW(v[1], std::out_of_range);
    EXPECT_THROW(v[-1], std::out_of_range);
}

// --- erase ---
TEST(VectorTest, EraseSingleElement) {
    knife::vector<int> v;
    v.push_back(10);
    v.erase(v.begin());
    EXPECT_EQ(v.size(), 0);

    knife::vector<int> v1 = { 1, 2, 3, 4};
    std::vector<int> v2 = {1, 2, 3, 4};
    v1.erase(v1.begin());
    v2.erase(v2.begin());
    EXPECT_EQ(v1[0], v2[0]);
    EXPECT_EQ(v1[0], 2);
}
// --- Iterators ---
TEST(VectorTest, IteratorsWork) {
    knife::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    int sum = 0;
    for (auto it = v.begin(); it != v.end(); ++it)
        sum += *it;
    EXPECT_EQ(sum, 6);
}
