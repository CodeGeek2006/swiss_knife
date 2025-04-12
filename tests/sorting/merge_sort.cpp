#include <gtest/gtest.h>
#include "merge_sort.hpp"
#include <vector>
#include <algorithm>

namespace ks = knife::sorting;

// Test empty vector
TEST(MergeSortTest, HandlesEmptyVector) {
    std::vector<int> empty;
    auto result = ks::merge_sort(empty);
    EXPECT_TRUE(result.empty());
}

// Test single-element vector
TEST(MergeSortTest, HandlesSingleElement) {
    std::vector<int> single{42};
    auto result = ks::merge_sort(single);
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], 42);
}

// Test already sorted vector
TEST(MergeSortTest, HandlesAlreadySorted) {
    std::vector<int> sorted{1, 2, 3, 4, 5};
    auto result = ks::merge_sort(sorted);
    EXPECT_TRUE(std::is_sorted(result.begin(), result.end()));
    EXPECT_EQ(result, sorted);
}

// Test reverse-sorted vector
TEST(MergeSortTest, HandlesReverseSorted) {
    std::vector<int> reverse{5, 4, 3, 2, 1};
    auto result = ks::merge_sort(reverse);
    EXPECT_TRUE(std::is_sorted(result.begin(), result.end()));
}

// Test random unsorted vector
TEST(MergeSortTest, HandlesRandomUnsorted) {
    std::vector<int> random{3, 1, 4, 1, 5, 9, 2, 6};
    auto result = ks::merge_sort(random);
    EXPECT_TRUE(std::is_sorted(result.begin(), result.end()));
}

// Test with duplicates
TEST(MergeSortTest, HandlesDuplicates) {
    std::vector<int> dupes{2, 2, 1, 1, 3, 3};
    auto result = ks::merge_sort(dupes);
    EXPECT_TRUE(std::is_sorted(result.begin(), result.end()));
}

// Test with custom type (e.g., strings)
TEST(MergeSortTest, HandlesStrings) {
    std::vector<std::string> strings{"banana", "apple", "cherry"};
    auto result = ks::merge_sort(strings);
    EXPECT_TRUE(std::is_sorted(result.begin(), result.end()));
    EXPECT_EQ(result, (std::vector<std::string>{"apple", "banana", "cherry"}));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
