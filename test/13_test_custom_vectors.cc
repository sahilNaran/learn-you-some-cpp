#include "13_custom_vectors.h"
#include "catch.hpp"

TEST_CASE("MyVector basic operations", "[myvector]") {
  SECTION("Default constructor") {
    MyVector<int> vec;
    REQUIRE(vec.empty());
    REQUIRE(vec.get_size() == 0);
    REQUIRE(vec.get_capacity() == 0);
  }

  SECTION("Constructor with capacity") {
    MyVector<int> vec(5);
    REQUIRE(vec.empty());
    REQUIRE(vec.get_size() == 0);
    REQUIRE(vec.get_capacity() == 5);
  }

  SECTION("push_back and size") {
    MyVector<int> vec;
    vec.push_back(1);
    REQUIRE(vec.get_size() == 1);
    REQUIRE_FALSE(vec.empty());

    vec.push_back(2);
    vec.push_back(3);
    REQUIRE(vec.get_size() == 3);
  }

  SECTION("Element access") {
    MyVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    REQUIRE(vec[0] == 10);
    REQUIRE(vec[1] == 20);
    REQUIRE(vec[2] == 30);

    REQUIRE(vec.at(0) == 10);
    REQUIRE(vec.at(1) == 20);
    REQUIRE(vec.at(2) == 30);
    REQUIRE_THROWS(vec.at(3));

    // Modify elements
    vec[1] = 25;
    REQUIRE(vec[1] == 25);
  }

  SECTION("pop_back") {
    MyVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    vec.pop_back();
    REQUIRE(vec.get_size() == 2);
    REQUIRE(vec[0] == 10);
    REQUIRE(vec[1] == 20);
  }

  SECTION("clear") {
    MyVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);

    vec.clear();
    REQUIRE(vec.empty());
    REQUIRE(vec.get_size() == 0);
  }

  SECTION("Auto-resizing") {
    MyVector<int> vec(2);
    REQUIRE(vec.get_capacity() == 2);

    vec.push_back(1);
    vec.push_back(2);
    REQUIRE(vec.get_capacity() == 2);

    vec.push_back(3); // Should trigger resize
    REQUIRE(vec.get_size() == 3);
    REQUIRE(vec.get_capacity() > 2);
  }

  SECTION("Reserve") {
    MyVector<int> vec;
    vec.reserve(10);
    REQUIRE(vec.get_capacity() == 10);
    REQUIRE(vec.get_size() == 0);

    // Adding elements shouldn't change capacity
    for (int i = 0; i < 10; i++) {
      vec.push_back(i);
    }
    REQUIRE(vec.get_capacity() == 10);

    // Adding one more should increase capacity
    vec.push_back(10);
    REQUIRE(vec.get_capacity() > 10);
  }
}

TEST_CASE("MyVector copy semantics", "[myvector]") {
  SECTION("Copy constructor") {
    MyVector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);

    MyVector<int> vec2(vec1);
    REQUIRE(vec2.get_size() == 3);
    REQUIRE(vec2[0] == 1);
    REQUIRE(vec2[1] == 2);
    REQUIRE(vec2[2] == 3);

    // Modifying vec2 shouldn't affect vec1
    vec2[0] = 10;
    REQUIRE(vec1[0] == 1);
    REQUIRE(vec2[0] == 10);
  }

  SECTION("Copy assignment") {
    MyVector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);

    MyVector<int> vec2;
    vec2 = vec1;
    REQUIRE(vec2.get_size() == 2);
    REQUIRE(vec2[0] == 1);
    REQUIRE(vec2[1] == 2);

    // Modifying vec2 shouldn't affect vec1
    vec2[0] = 10;
    REQUIRE(vec1[0] == 1);
    REQUIRE(vec2[0] == 10);
  }
}

TEST_CASE("MyVector iterators", "[myvector]") {
  SECTION("Iterator basics") {
    MyVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    auto it = vec.begin();
    REQUIRE(*it == 10);

    ++it;
    REQUIRE(*it == 20);

    it++;
    REQUIRE(*it == 30);

    REQUIRE(it != vec.begin());
    REQUIRE(++it == vec.end());
  }

  SECTION("Iterator-based for loop") {
    MyVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    int sum = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
      sum += *it;
    }
    REQUIRE(sum == 60);
  }

  SECTION("insert") {
    MyVector<int> vec;
    vec.push_back(10);
    vec.push_back(30);

    // Insert at the beginning
    auto it = vec.insert(vec.begin(), 5);
    REQUIRE(*it == 5);
    REQUIRE(vec.get_size() == 3);
    REQUIRE(vec[0] == 5);
    REQUIRE(vec[1] == 10);
    REQUIRE(vec[2] == 30);

    // Insert in the middle
    it = vec.insert(vec.begin() + 2, 20);
    REQUIRE(*it == 20);
    REQUIRE(vec.get_size() == 4);
    REQUIRE(vec[0] == 5);
    REQUIRE(vec[1] == 10);
    REQUIRE(vec[2] == 20);
    REQUIRE(vec[3] == 30);

    // Insert at the end
    it = vec.insert(vec.end(), 40);
    REQUIRE(*it == 40);
    REQUIRE(vec.get_size() == 5);
    REQUIRE(vec[4] == 40);
  }

  SECTION("erase") {
    MyVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    // Erase from the middle
    auto it = vec.erase(vec.begin() + 1);
    REQUIRE(*it == 30); // Should point to the element after the erased one
    REQUIRE(vec.get_size() == 3);
    REQUIRE(vec[0] == 10);
    REQUIRE(vec[1] == 30);
    REQUIRE(vec[2] == 40);

    // Erase from the beginning
    it = vec.erase(vec.begin());
    REQUIRE(*it == 30);
    REQUIRE(vec.get_size() == 2);
    REQUIRE(vec[0] == 30);
    REQUIRE(vec[1] == 40);

    // Erase from the end
    it = vec.erase(vec.begin() + 1);
    REQUIRE(it == vec.end());
    REQUIRE(vec.get_size() == 1);
    REQUIRE(vec[0] == 30);
  }
}
