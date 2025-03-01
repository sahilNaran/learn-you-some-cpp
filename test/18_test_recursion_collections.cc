#include "18_recursion_collections.h"
#include "catch.hpp"

TEST_CASE("Recursive functions with collections", "[recursion]") {
  SECTION("Binary search") {
    std::vector<int> sorted_arr = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    REQUIRE(binary_search(sorted_arr, 10) == 0);
    REQUIRE(binary_search(sorted_arr, 50) == 4);
    REQUIRE(binary_search(sorted_arr, 90) == 8);
    REQUIRE(binary_search(sorted_arr, 25) == -1);
    REQUIRE(binary_search(sorted_arr, 100) == -1);
    REQUIRE(binary_search({}, 5) == -1); // Empty array
  }

  SECTION("Sum array") {
    REQUIRE(sum_array({1, 2, 3, 4, 5}) == 15);
    REQUIRE(sum_array({-1, -2, -3}) == -6);
    REQUIRE(sum_array({}) == 0); // Empty array
  }

  SECTION("Find max") {
    REQUIRE(find_max({1, 3, 5, 7, 9}) == 9);
    REQUIRE(find_max({9, 5, 3, 7, 1}) == 9);
    REQUIRE(find_max({-5, -3, -1}) == -1);
    REQUIRE_THROWS(find_max({})); // Empty array
  }

  SECTION("Count occurrences") {
    REQUIRE(count_occurrences({1, 2, 3, 2, 4, 2}, 2) == 3);
    REQUIRE(count_occurrences({5, 5, 5, 5}, 5) == 4);
    REQUIRE(count_occurrences({1, 2, 3, 4}, 5) == 0);
    REQUIRE(count_occurrences({}, 5) == 0); // Empty array
  }

  SECTION("Optimized Fibonacci") {
    REQUIRE(fibonacci_optimized(0) == 0);
    REQUIRE(fibonacci_optimized(1) == 1);
    REQUIRE(fibonacci_optimized(2) == 1);
    REQUIRE(fibonacci_optimized(5) == 5);
    REQUIRE(fibonacci_optimized(10) == 55);
    REQUIRE(fibonacci_optimized(30) == 832040);
    REQUIRE_THROWS(fibonacci_optimized(-1));
  }
}
