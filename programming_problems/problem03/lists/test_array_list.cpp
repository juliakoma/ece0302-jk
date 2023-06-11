#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

TEST_CASE( "Default Constructor", "[ArrayList]" ) {
  ArrayList<int> list;

  REQUIRE(list.getLength() == 0);
}

TEST_CASE( "Insert Method", "[ArrayList]" ) {
  ArrayList<int> list;

  REQUIRE(list.getLength() == 0);

  list.insert(0,1);
  list.insert(1,2);
  list.insert(2,3);
  list.insert(3,4);

  REQUIRE(list.getLength() == 4);

  REQUIRE(list.getEntry(0) == 1);
  REQUIRE(list.getEntry(1) == 2);
  REQUIRE(list.getEntry(2) == 3);
  REQUIRE(list.getEntry(3) == 4);
}

TEST_CASE( "Remove Method", "[ArrayList]" ) {
  ArrayList<int> list;

  list.insert(0,5); // 0
  list.insert(1,6); // 1
  list.insert(2,7); // 2 
  list.insert(3,8); // 3

  list.insert(6, 17);

  REQUIRE(list.getLength() == 4);

  list.remove(2);
  REQUIRE(list.getLength() == 3);
  REQUIRE_FALSE(list.remove(5));
  REQUIRE_FALSE(list.insert(10,1));
}

TEST_CASE( "Set Entry Method", "[ArrayList]" ) {
  ArrayList<int> list;

  list.insert(0,1); // 0
  list.insert(1,2); // 1
  list.insert(2,3); // 2 
  list.insert(3,4); // 3

  REQUIRE(list.getLength() == 4);

  list.setEntry(2,7);
  REQUIRE(list.getEntry(2) == 7);
  REQUIRE(list.getLength() == 4);
}

TEST_CASE( "Clear Method", "[ArrayList]" ) {
  ArrayList<int> list;

  REQUIRE(list.getLength() == 0);

  list.insert(0,1);
  list.insert(1,2);

  REQUIRE(list.getLength() == 2);

  list.clear();
  REQUIRE(list.getLength() == 0);
}

