#include <gtest/gtest.h>
#include "../../knife/knife.hpp"
#include <vector>
#include <iostream>

TEST(QuickSortTest, BasicAssertions) {
    //just a simple case
    std::vector<int> nums{7, 1, 4, 9};
    std::vector<int> sorted_nums{1, 4, 7, 9};
    knife::quick_sort(nums.begin(), nums.end(), [](const int& a, const int& b) -> bool {
        return a < b;
    });

    EXPECT_EQ(sorted_nums, nums);

    //custom comparator, reverse
    sorted_nums = std::vector<int>{9, 7, 4, 1};
    knife::quick_sort(nums.begin(), nums.end(), [](const int& a, const int& b) -> bool {
        return a > b;
    });

    EXPECT_EQ(sorted_nums, nums);

    //empty range
    sorted_nums.clear();
    nums.clear();
    knife::quick_sort(nums.begin(), nums.end(), [](const int& a, const int& b) -> bool {
        return a < b;
    });

    EXPECT_EQ(sorted_nums, nums);

    //negative numbers
    nums = std::vector<int>{-7, 1, -4, 9};
    sorted_nums = std::vector<int>{-7, -4, 1, 9};
    knife::quick_sort(nums.begin(), nums.end(), [](const int& a, const int& b) -> bool {
        return a < b;
    });

    EXPECT_EQ(sorted_nums, nums);
}