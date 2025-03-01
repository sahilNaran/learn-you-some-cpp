#include "12_stl_algorithms.h"
#include "catch.hpp"

TEST_CASE("STL algorithm operations", "[stl_algorithms]") {
  SECTION("Double values") {
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> expected = {2, 4, 6, 8, 10};
    REQUIRE(double_values(input) == expected);
  }

  SECTION("All positive") {
    REQUIRE(all_positive({1, 2, 3, 4, 5}));
    REQUIRE_FALSE(all_positive({1, 2, -3, 4, 5}));
    REQUIRE(all_positive({})); // Edge case - empty vector
  }

  SECTION("Sum elements") {
    REQUIRE(sum_elements({1, 2, 3, 4, 5}) == 15);
    REQUIRE(sum_elements({-1, -2, 3, 4}) == 4);
    REQUIRE(sum_elements({}) == 0); // Edge case - empty vector
  }

  SECTION("Sort by second") {
    std::vector<std::pair<std::string, int>> pairs = {
        {"apple", 5}, {"banana", 2}, {"orange", 10}, {"grape", 7}};

    sort_by_second(pairs);

    // Should be sorted by second element (descending)
    REQUIRE(pairs[0].first == "orange");
    REQUIRE(pairs[1].first == "grape");
    REQUIRE(pairs[2].first == "apple");
    REQUIRE(pairs[3].first == "banana");
  }

  SECTION("Filter even") {
    std::vector<int> input = {1, 2, 3, 4, 5, 6};
    std::vector<int> expected = {2, 4, 6};
    REQUIRE(filter_even(input) == expected);

    REQUIRE(filter_even({1, 3, 5}).empty()); // No even numbers
    REQUIRE(filter_even({}).empty());        // Edge case - empty vector
  }
}
