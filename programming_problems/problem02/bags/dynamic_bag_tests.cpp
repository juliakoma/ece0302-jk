#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dynamic_bag.hpp"

// force template expansion for ints
template class DynamicBag<int>;

TEST_CASE("Calling all public members", "[DynamicBag]"){
  DynamicBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);
}

TEST_CASE("Default Constructor", "[DynamicBag]"){
  DynamicBag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());
}

TEST_CASE("Copy constructor", "[DynamicBag]") {
    // Create an original bag
    DynamicBag<int> bag1;

    DynamicBag<int> bag2 = bag1;

    bag1 = bag2;
}

TEST_CASE("Add Method", "[DynamicBag]"){
  DynamicBag<int> bag;

  // Test case for adding an item to an empty bag
  SECTION("Add item to an empty bag") {
    int item = 10;
    bool added = bag.add(item);
    REQUIRE(added == true);
    REQUIRE(bag.getFrequencyOf(item) == 1);
    REQUIRE(bag.getCurrentSize() == 1);
  }

  bag.add(20);
  bag.add(30);

  // Test case for adding an item to a non-empty bag
  SECTION("Add item to a non-empty bag") {
    int item = 40;
    bool added = bag.add(item);
    REQUIRE(added == true);
    REQUIRE(bag.getFrequencyOf(item) == 1);
    REQUIRE(bag.getCurrentSize() == 3);
  }
}

TEST_CASE("Remove Method", "[DynamicBag]"){
  DynamicBag<int> bag;

  // Test case for removing item from an empty bag
  SECTION("Remove item from an empty bag") {
    int item = 10;
    bool removed = bag.remove(item);
    REQUIRE(removed == false);
  }

  bag.add(10);
  bag.add(20);
  bag.add(30);
  bag.add(40);

  // Test case for removing an item that exists in the bag
  SECTION("Remove existing item from the bag") {
    int item = 20;
    bool removed = bag.remove(item);
    REQUIRE(removed == true);
  }

  // Test case for removing an item that doesn't exist in the bag
  SECTION("Remove non-existing item from the bag") {
    int item = 50;
    bool removed = bag.remove(item);
    REQUIRE(removed == true);
  }
}

TEST_CASE("isEmpty Method", "[DynamicBag]"){
  DynamicBag<int> bag;
    {
    REQUIRE(bag.isEmpty() == true); // Expecting the bag to be initially empty

    // Add an element to the bag
    bag.add(10);

    REQUIRE(bag.isEmpty() == false); // Expecting the bag to be non-empty after adding an element

    // Remove the element from the bag
    bag.remove(10);

    REQUIRE(bag.isEmpty() == true); // Expecting the bag to be empty after removing the element
  }

  // Test case for a non-empty bag
  {
    // Add some elements to the bag
    bag.add(20);
    bag.add(30);

    REQUIRE(bag.isEmpty() == false); // Expecting the bag to be non-empty
  }
}

TEST_CASE("getCurrentSize Method", "[DynamicBag]"){
  DynamicBag<int> bag;
  // Check initial size
  REQUIRE(bag.getCurrentSize() == 0);

  // Add some elements to the bag
  bag.add(10);
  bag.add(20);
  bag.add(30);

  // Check size after adding elements
  REQUIRE(bag.getCurrentSize() == 3);

  // Remove an element from the bag
  bag.remove(10);

  // Check size after removing an element
  REQUIRE(bag.getCurrentSize() == 2);
}


TEST_CASE("Contains Method 1", "[DynamicBag]"){
  DynamicBag<int> bag;

  // Add elements to the bag
  bag.add(10);
  bag.add(20);
  bag.add(30);

  // Test case for item exists in the bag
  int item = 20;
  bool containsItem = bag.contains(item);
  REQUIRE(containsItem == true);
}

TEST_CASE("Contains Method 2", "[DynamicBag]"){
  DynamicBag<int> bag;
  // Test case for item does not exist in the bag
  int item = 40;
  bool containsItem = bag.contains(item);
  REQUIRE(containsItem == false);
}

TEST_CASE("Clear Method", "[DynamicBag]"){
  DynamicBag<int> bag;

  // Add elements to the bag
  bag.add(10);
  bag.add(20);
  bag.add(30);

  // Check initial size
  REQUIRE(bag.getCurrentSize() == 3);

  // Clear the bag
  bag.clear();

  // Check size after clearing
  REQUIRE(bag.getCurrentSize() == 0);

}

TEST_CASE("Frequency Method", "[DynamicBag]"){
  DynamicBag<int> bag;

  // Add elements to the bag
  bag.add(10);
  bag.add(20);
  bag.add(10);
  bag.add(30);
  bag.add(10);

  // Test case for existing item
  {
    int item = 10;
    std::size_t frequency = bag.getFrequencyOf(item);
    REQUIRE(frequency == 3);
  }

  // Test case for non-existing item
  {
    int item = 40;
    std::size_t frequency = bag.getFrequencyOf(item);
    REQUIRE(frequency == 0);
  }
}