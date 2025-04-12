#include <gtest/gtest.h>
#include "../../knife/knife.hpp"
#include <vector>
#include <algorithm>
#include <string>

// Test empty vector
TEST(MergeSortTest, HandlesEmptyVector) {
    std::vector<int> empty;
    knife::sorting::merge_sort(empty.data(), empty.data() + empty.size());
    EXPECT_TRUE(empty.empty());
}

// Test single-element vector
TEST(MergeSortTest, HandlesSingleElement) {
    std::vector<int> single{42};
    knife::sorting::merge_sort(single.data(), single.data() + single.size());
    ASSERT_EQ(single.size(), 1);
    EXPECT_EQ(single[0], 42);
}

// Test already sorted vector
TEST(MergeSortTest, HandlesAlreadySorted) {
    std::vector<int> sorted{1, 2, 3, 4, 5};
    auto sorted_copy = sorted;
    knife::sorting::merge_sort(sorted.data(), sorted.data() + sorted.size());
    EXPECT_TRUE(std::is_sorted(sorted.begin(), sorted.end()));
    EXPECT_EQ(sorted, sorted_copy);
}

// Test reverse-sorted vector
TEST(MergeSortTest, HandlesReverseSorted) {
    std::vector<int> reverse{5, 4, 3, 2, 1};
    knife::sorting::merge_sort(reverse.data(), reverse.data() + reverse.size());
    EXPECT_TRUE(std::is_sorted(reverse.begin(), reverse.end()));
}

// Test random unsorted vector
TEST(MergeSortTest, HandlesRandomUnsorted) {
    std::vector<int> random{3, 1, 4, 1, 5, 9, 2, 6};
    knife::sorting::merge_sort(random.data(), random.data() + random.size());
    EXPECT_TRUE(std::is_sorted(random.begin(), random.end()));
}

// Test with duplicates
TEST(MergeSortTest, HandlesDuplicates) {
    std::vector<int> dupes{2, 2, 1, 1, 3, 3};
    knife::sorting::merge_sort(dupes.data(), dupes.data() + dupes.size());
    EXPECT_TRUE(std::is_sorted(dupes.begin(), dupes.end()));
}

// Test with custom type (e.g., strings)
TEST(MergeSortTest, HandlesStrings) {
    std::vector<std::string> strings{"banana", "apple", "cherry"};
    knife::sorting::merge_sort(strings.data(), strings.data() + strings.size());
    EXPECT_TRUE(std::is_sorted(strings.begin(), strings.end()));
    EXPECT_EQ(strings, (std::vector<std::string>{"apple", "banana", "cherry"}));
}

// Test with custom comparator
TEST(MergeSortTest, HandlesCustomComparator) {
    std::vector<int> numbers{3, 1, 4, 1, 5};
    knife::sorting::merge_sort(numbers.data(), numbers.data() + numbers.size(), 
        [](int a, int b) { return a > b; });
    EXPECT_TRUE(std::is_sorted(numbers.begin(), numbers.end(), std::greater<int>()));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}