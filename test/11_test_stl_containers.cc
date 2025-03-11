#include "11_stl_containers.h"
#include "catch.hpp"

TEST_CASE("STL container operations", "[stl]") {
  SECTION("Most frequent element") {
    REQUIRE(most_frequent({1, 2, 3, 1, 2, 1, 3, 1}) == 1);
    REQUIRE(most_frequent({5, 5, 5, 2, 2, 2, 2}) == 2);
    REQUIRE(most_frequent({1}) == 1);
  }

  SECTION("Remove duplicates") {
    std::vector<int> result1 = remove_duplicates({1, 2, 3, 1, 2});
    std::vector<int> expected1 = {1, 2, 3};
    REQUIRE(result1 == expected1);

    std::vector<int> result2 = remove_duplicates({4, 4, 4, 4});
    std::vector<int> expected2 = {4};
    REQUIRE(result2 == expected2);
  }

  SECTION("Word counter") {
    std::map<std::string, int> result =
        count_words({"apple", "banana", "apple", "orange", "banana", "apple"});

    REQUIRE(result["apple"] == 3);
    REQUIRE(result["banana"] == 2);
    REQUIRE(result["orange"] == 1);
    REQUIRE(result.size() == 3);
  }

  SECTION("Find intersection") {
    std::vector<int> result = find_intersection({1, 2, 3, 4}, {3, 4, 5, 6});
    std::sort(result.begin(), result.end()); // Sort for comparison
    std::vector<int> expected = {3, 4};
    REQUIRE(result == expected);

    std::vector<int> result2 = find_intersection({1, 2, 3}, {4, 5, 6});
    REQUIRE(result2.empty());

    std::vector<int> result3 = find_intersection({1, 2, 3}, {2, 2, 3, 3});
    std::sort(result3.begin(), result3.end()); // Sort for comparison
    std::vector<int> expected3 = {2, 3};
    REQUIRE(result3 == expected3);
  }
}
