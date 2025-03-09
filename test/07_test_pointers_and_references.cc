#include "07_pointers_and_references.h"
#include "catch.hpp"

TEST_CASE("Pointer operations work correctly", "[pointers_and_references]") {
  SECTION("Swap with pointers") {
    int a = 5, b = 10;
    swap_ptr(&a, &b);
    REQUIRE(a == 10);
    REQUIRE(b == 5);
  }

  SECTION("Swap with references") {
    int a = 5, b = 10;
    swap_ref(a, b);
    REQUIRE(a == 10);
    REQUIRE(b == 5);
  }

  SECTION("Array reversal") {
    int arr[] = {1, 2, 3, 4, 5};
    reverse_array(arr, 5);
    REQUIRE(arr[0] == 5);
    REQUIRE(arr[1] == 4);
    REQUIRE(arr[2] == 3);
    REQUIRE(arr[3] == 2);
    REQUIRE(arr[4] == 1);
  }

  SECTION("Find min and max") {
    int arr[] = {3, 1, 7, 5, 2};
    int min = 0, max = 0;
    find_min_max(arr, 5, &min, &max);
    REQUIRE(min == 1);
    REQUIRE(max == 7);
  }
}
