#include "01_basic_math.h"
#include "catch.hpp"

TEST_CASE("Basic math operations work correctly", "[basic_math]") {
  SECTION("Addition") {
    REQUIRE(add(5, 3) == 8);
    REQUIRE(add(-1, 1) == 0);
    REQUIRE(add(0, 0) == 0);
  }

  SECTION("Subtraction") {
    REQUIRE(subtract(5, 3) == 2);
    REQUIRE(subtract(3, 5) == -2);
    REQUIRE(subtract(0, 0) == 0);
  }

  SECTION("Multiplication") {
    REQUIRE(multiply(5, 3) == 15);
    REQUIRE(multiply(-2, 4) == -8);
    REQUIRE(multiply(0, 5) == 0);
  }

  SECTION("Division") {
    REQUIRE(divide(6, 3) == 2.0);
    REQUIRE(divide(5, 2) == 2.5);
    REQUIRE_THROWS(divide(1, 0));
  }
}
