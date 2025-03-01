#include "10_algorithm_basics.h"
#include "catch.hpp"
#include <iostream>

TEST_CASE("Search algorithms correctness", "[search]") {
  int arr[] = {1, 5, 10, 15, 20, 25, 30, 35, 40, 45};
  int size = sizeof(arr) / sizeof(arr[0]);

  SECTION("Linear search") {
    REQUIRE(linear_search(arr, size, 15) == 3);
    REQUIRE(linear_search(arr, size, 25) == 5);
    REQUIRE(linear_search(arr, size, 100) == -1);
  }

  SECTION("Binary search") {
    REQUIRE(binary_search(arr, size, 15) == 3);
    REQUIRE(binary_search(arr, size, 25) == 5);
    REQUIRE(binary_search(arr, size, 100) == -1);
  }
}

TEST_CASE("Count occurrences", "[count]") {
  int arr[] = {1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  REQUIRE(count_occurrences_linear(arr, size, 2) == 3);
  REQUIRE(count_occurrences_linear(arr, size, 5) == 5);
  REQUIRE(count_occurrences_linear(arr, size, 6) == 0);

  REQUIRE(count_occurrences_efficient(arr, size, 2) == 3);
  REQUIRE(count_occurrences_efficient(arr, size, 5) == 5);
  REQUIRE(count_occurrences_efficient(arr, size, 6) == 0);
}

TEST_CASE("Algorithm efficiency comparison", "[efficiency]") {
  // Generate a large sorted array
  const int size = 1000000;
  std::vector<int> large_arr(size);

  for (int i = 0; i < size; i++) {
    large_arr[i] = i / 100; // Creates some duplicates
  }

  int search_value = 5000;

  // Measure linear search time
  auto start = std::chrono::high_resolution_clock::now();
  count_occurrences_linear(large_arr.data(), size, search_value);
  auto end = std::chrono::high_resolution_clock::now();
  auto linear_time =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start)
          .count();

  // Measure efficient search time
  start = std::chrono::high_resolution_clock::now();
  count_occurrences_efficient(large_arr.data(), size, search_value);
  end = std::chrono::high_resolution_clock::now();
  auto efficient_time =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start)
          .count();

  std::cout << "Linear search time: " << linear_time << " µs" << std::endl;
  std::cout << "Efficient search time: " << efficient_time << " µs"
            << std::endl;

  // The efficient algorithm should be significantly faster
  REQUIRE(linear_time > efficient_time);
}
