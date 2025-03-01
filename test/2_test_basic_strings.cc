#include "basic_strings.h"
#include "catch.hpp"

TEST_CASE("String operations work correctly", "[basic_strings]") {
  SECTION("String concatenation") {
    REQUIRE(concatenate("ape ", "strong") == "ape strong");
    REQUIRE(concatenate("", "banana") == "banana");
    REQUIRE(concatenate("ook", "") == "ook");
    REQUIRE(concatenate("", "") == "");
  }

  SECTION("Substring extraction") {
    REQUIRE(substring("banana", 0, 3) == "ban");
    REQUIRE(substring("ape together strong", 4, 8) == "together");
    REQUIRE(substring("short", 0, 10) == "short");
    REQUIRE(substring("test", 4, 1) == "");
  }

  SECTION("String contains") {
    REQUIRE(contains("ape together strong", "together") == true);
    REQUIRE(contains("banana", "nan") == true);
    REQUIRE(contains("test", "best") == false);
    REQUIRE(contains("", "") == true);
  }

  SECTION("String case conversion") {
    REQUIRE(toUpper("ape") == "APE");
    REQUIRE(toUpper("Ape Together Strong") == "APE TOGETHER STRONG");
    REQUIRE(toUpper("") == "");

    REQUIRE(toLower("APE") == "ape");
    REQUIRE(toLower("Ape Together STRONG") == "ape together strong");
    REQUIRE(toLower("") == "");
  }

  SECTION("Find character in string") {
    REQUIRE(findFirstOf("banana", 'a') == 1);
    REQUIRE(findFirstOf("test", 'x') == std::string::npos);
    REQUIRE(findFirstOf("", 'a') == std::string::npos);
  }

  SECTION("Replace substring") {
    REQUIRE(replace("ape eat banana", "banana", "apple") == "ape eat apple");
    REQUIRE(replace("test test test", "test", "check") == "check check check");
    REQUIRE(replace("no match here", "missing", "found") == "no match here");
    REQUIRE(replace("", "empty", "full") == "");
  }
}
