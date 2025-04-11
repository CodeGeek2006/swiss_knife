#include <gtest/gtest.h>
#include "/Users/z.baxtiyorov/CLionProjects/swiss_knife/tests/containers/../../knife/containers/list.hpp"

    // Test fixture class for List
    class ListTest : public ::testing::Test {
    protected:
        knife::List<int> list;  // List object to be used in the tests

        // SetUp function to add initial elements to the list
        void SetUp() override {
            list.addFront(10);  // Add an element to the front
            list.addBack(20);   // Add an element to the back
            list.addFront(5);   // Add another element to the front
        }
    };

    // Test to check if adding elements to the front works
    TEST_F(ListTest, AddFrontTest) {
        list.addFront(100);  // Add 100 to the front
        EXPECT_EQ(list.getFront(), 100);  // The front should be 100
    }

    // Test to check if adding elements to the back works
    TEST_F(ListTest, AddBackTest) {
        list.addBack(30);  // Add 30 to the back
        EXPECT_EQ(list.getAt(3), 30);  // The last element (at index 3) should be 30
    }

    // Test to check if getting the front element works
    TEST_F(ListTest, GetFrontTest) {
        EXPECT_EQ(list.getFront(), 5);  // The first element should be 5 after SetUp
    }

    // Test to check if removing the front element works
    TEST_F(ListTest, RemoveFrontTest) {
        list.removeFront();  // Remove the front element (5)
        EXPECT_EQ(list.getFront(), 10);  // The new front should be 10
    }

    // Test to check if removing the tail element works
    TEST_F(ListTest, RemoveTailTest) {
        list.removeTail();  // Remove the tail element (20)
        EXPECT_EQ(list.getAt(1), 10);  // The second element (index 1) should now be 10
    }

    // Test to check if getting an element at a specific index works
    TEST_F(ListTest, GetAtTest) {
        EXPECT_EQ(list.getAt(0), 5);  // First element should be 5
        EXPECT_EQ(list.getAt(1), 10);  // Second element should be 10
        EXPECT_EQ(list.getAt(2), 20);  // Third element should be 20
    }

    // Test to check if removing an element
   TEST_F(ListTest, RemoveAtTest) {
    list.addFront(5);
    list.addFront(10);
    list.addFront(15);  // Now the list is: 15, 10, 5

    list.removeAt(1);  // Remove element at index 1 (value 10)

    // After removal, the list should contain: 15, 5
    EXPECT_EQ(list.getAt(0), 15);  // The element at index 0 should be 15
    EXPECT_EQ(list.getAt(1), 5);   // The element at index 1 should be 5 (not 10 anymore)

    // Trying to get the removed element should throw an exception
    EXPECT_THROW(list.getAt(-10), std::out_of_range);  // Index 1 should throw an exception
}


    // Test to check if inserting an element at a specific index works
    TEST_F(ListTest, InsertAtTest) {
        list.insertAd(15, 1);  // Insert 15 at index 1
        EXPECT_EQ(list.getAt(1), 15);  // The element at index 1 should now be 15
    }

    // Test for edge case: Removing from an empty list (front)
    TEST_F(ListTest, RemoveFromEmptyListTest) {
        list.removeFront();  // Remove the first element
        list.removeFront();  // Remove the second element
        list.removeFront();  // Now the list should be empty
        EXPECT_THROW(list.removeFront(), std::runtime_error);  // Trying to remove from empty list should throw an exception
    }

    // Test for edge case: Removing from an empty list (tail)
    TEST_F(ListTest, RemoveTailFromEmptyListTest) {
        list.removeTail();  // Remove the tail element
        list.removeTail();  // Remove the new tail element
        list.removeTail();  // Now the list should be empty
        EXPECT_THROW(list.removeTail(), std::runtime_error);  // Trying to remove from empty list should throw an exception
    }

    // Test for edge case: Invalid index access
    TEST_F(ListTest, InvalidIndexTest) {
        EXPECT_THROW(list.getAt(5), std::out_of_range);  // Accessing an out-of-range index should throw an exception
    }


// Main entry point for running the Google Test framework
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
