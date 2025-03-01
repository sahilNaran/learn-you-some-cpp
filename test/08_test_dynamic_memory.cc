#include "08_dynamic_memory.h"
#include "catch.hpp"

TEST_CASE("Dynamic array operations work correctly", "[dynamic_array]") {
  SECTION("Construction and basic operations") {
    DynamicArray arr(5);
    REQUIRE(arr.getSize() == 5);

    arr.set(0, 10);
    arr.set(1, 20);
    REQUIRE(arr.get(0) == 10);
    REQUIRE(arr.get(1) == 20);
  }

  SECTION("Bounds checking") {
    DynamicArray arr(3);
    REQUIRE_THROWS(arr.get(5));
    REQUIRE_THROWS(arr.set(5, 10));
  }

  SECTION("Resizing") {
    DynamicArray arr(3);
    arr.set(0, 10);
    arr.set(1, 20);
    arr.set(2, 30);

    arr.resize(5);
    REQUIRE(arr.getSize() == 5);
    REQUIRE(arr.get(0) == 10);
    REQUIRE(arr.get(1) == 20);
    REQUIRE(arr.get(2) == 30);

    arr.set(3, 40);
    arr.set(4, 50);
    REQUIRE(arr.get(3) == 40);
    REQUIRE(arr.get(4) == 50);

    arr.resize(2);
    REQUIRE(arr.getSize() == 2);
    REQUIRE(arr.get(0) == 10);
    REQUIRE(arr.get(1) == 20);
    REQUIRE_THROWS(arr.get(2));
  }
}
