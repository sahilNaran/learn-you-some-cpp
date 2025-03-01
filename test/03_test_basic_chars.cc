#include "03_basic_chars.h"
#include "catch.hpp"

TEST_CASE("Character operations work correctly", "[char]") {
  SECTION("Character type checking") {
    REQUIRE(isDigit('0') == true);
    REQUIRE(isDigit('9') == true);
    REQUIRE(isDigit('a') == false);

    REQUIRE(isAlpha('a') == true);
    REQUIRE(isAlpha('Z') == true);
    REQUIRE(isAlpha('5') == false);

    REQUIRE(isAlphaNum('a') == true);
    REQUIRE(isAlphaNum('5') == true);
    REQUIRE(isAlphaNum('!') == false);

    REQUIRE(isLower('a') == true);
    REQUIRE(isLower('z') == true);
    REQUIRE(isLower('A') == false);

    REQUIRE(isUpper('A') == true);
    REQUIRE(isUpper('Z') == true);
    REQUIRE(isUpper('a') == false);
  }

  SECTION("Character case conversion") {
    REQUIRE(toUpperChar('a') == 'A');
    REQUIRE(toUpperChar('z') == 'Z');
    REQUIRE(toUpperChar('A') == 'A');
    REQUIRE(toUpperChar('5') == '5');

    REQUIRE(toLowerChar('A') == 'a');
    REQUIRE(toLowerChar('Z') == 'z');
    REQUIRE(toLowerChar('a') == 'a');
    REQUIRE(toLowerChar('5') == '5');
  }

  SECTION("Special characters") {
    REQUIRE(isDigit(' ') == false);
    REQUIRE(isDigit('\n') == false);
    REQUIRE(isDigit('\0') == false);

    REQUIRE(isAlpha(' ') == false);
    REQUIRE(isAlpha('\t') == false);

    REQUIRE(isAlphaNum('_') == false);
    REQUIRE(isAlphaNum(' ') == false);
  }
}
