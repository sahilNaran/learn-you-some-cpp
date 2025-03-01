#include "05_basic_functions.h"
#include "catch.hpp"

TEST_CASE("Temperature conversions work correctly", "[temp]") {
  SECTION("Celsius to Fahrenheit") {
    REQUIRE(temperature::to_fahrenheit(0.0) == Approx(32.0));
    REQUIRE(temperature::to_fahrenheit(100.0) == Approx(212.0));
    REQUIRE(temperature::to_fahrenheit(-40.0) == Approx(-40.0));
  }

  SECTION("Fahrenheit to Celsius") {
    REQUIRE(temperature::to_celsius(32.0) == Approx(0.0));
    REQUIRE(temperature::to_celsius(212.0) == Approx(100.0));
    REQUIRE(temperature::to_celsius(-40.0) == Approx(-40.0));
  }

  SECTION("Freezing detection") {
    REQUIRE(temperature::is_freezing(0.0));
    REQUIRE(temperature::is_freezing(-10.0));
    REQUIRE_FALSE(temperature::is_freezing(5.0));
    REQUIRE(temperature::is_freezing(32.0, false));
    REQUIRE_FALSE(temperature::is_freezing(40.0, false));
  }
}
