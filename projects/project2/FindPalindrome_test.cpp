#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"


// There should be at least one test per FindPalindrome method

/*TEST_CASE( "Test adding a non-allowable word", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
}

TEST_CASE("test recursion", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));
	REQUIRE(b.number() == 6);
}

TEST_CASE("Testing add function and cutTest1 method") {
    FindPalindrome b; // Create an instance of the FindPalindrome class

    std::vector<std::string> test1 = {"radar"};
    REQUIRE(b.cutTest1(test1));

	std::vector<std::string> test2 = {"no"};
    REQUIRE(!b.cutTest1(test2));
}

TEST_CASE("Testing add function and cutTest2 method") {
    FindPalindrome b; // Create an instance of the FindPalindrome class

	std::vector<std::string> test3 = {"ka"};
	std::vector<std::string> test4 = {"yak"};

	REQUIRE(b.add(test3));
	REQUIRE(b.add(test4));

	REQUIRE(b.cutTest2(test3, test4));
	test3.clear();
}

TEST_CASE("Recursive function") {
    FindPalindrome b; // Create an instance of the FindPalindrome class

	std::vector<std::string> str = {"a"};
	std::vector<std::string> sent;

	str.push_back("AA");
	str.push_back("Aa");
}*/

TEST_CASE("Testing full palindrome") {
    FindPalindrome b; // Create an instance of the FindPalindrome class

	std::vector<std::string> test3;
	test3.push_back("sit");
	test3.push_back("on");
	test3.push_back("a");
	test3.push_back("potato");
	test3.push_back("pan");
	test3.push_back("otis");
	REQUIRE(b.add(test3));

	REQUIRE(b.cutTest1(test3));
	REQUIRE(b.number() == 1);

	test3.clear();
}

/*TEST_CASE("Testing add vector") {
    FindPalindrome b; // Create an instance of the FindPalindrome class

	std::vector<std::string> test3;
	test3.push_back("ba");
	test3.push_back("0ab");
	test3.push_back("0bc");
	test3.push_back("2bd");
	test3.push_back("0be");
	test3.push_back("0");
	REQUIRE(b.add(test3));

	//REQUIRE(b.cutTest2(test3, test4));
	test3.clear();
}

TEST_CASE("Testing cut test 1") {
    FindPalindrome b; // Create an instance of the FindPalindrome class

	std::vector<std::string> test3;
	test3.push_back("b");
	test3.push_back("0");
  	REQUIRE(!b.cutTest1(test3));
	//REQUIRE(b.add(test3));

	//REQUIRE(b.cutTest2(test3, test4));
	test3.clear();
}*/

