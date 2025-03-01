#define CATCH_CONFIG_MAIN
#include "00_greet.h"
#include "catch.hpp"

TEST_CASE("Greeting returns the correct message", "[greeting]") {
  REQUIRE(greet() == "Hello, cpp!");
}
