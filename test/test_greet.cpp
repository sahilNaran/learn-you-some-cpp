#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "greet.h"

TEST_CASE("Greeting returns the correct message", "[greeting]") {
  REQUIRE(greet() == "Hello, cpp!");
}
