#include "16_linked_list_algorithms.h"
#include "catch.hpp"

TEST_CASE("Linked list algorithms", "[linkedlistalgorithms]") {
  SECTION("Find middle element - odd length") {
    SinglyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    REQUIRE(LinkedListAlgorithms<int>::find_middle(list) == 3);
  }

  SECTION("Find middle element - even length") {
    SinglyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    // For even length, return the second middle element
    REQUIRE(LinkedListAlgorithms<int>::find_middle(list) == 3);
  }

  SECTION("Find middle element - single element") {
    SinglyLinkedList<int> list;
    list.push_back(1);

    REQUIRE(LinkedListAlgorithms<int>::find_middle(list) == 1);
  }

  SECTION("Find middle element - empty list") {
    SinglyLinkedList<int> list;

    REQUIRE_THROWS(LinkedListAlgorithms<int>::find_middle(list));
  }

  SECTION("Cycle detection - with cycle") {
    auto list = LinkedListAlgorithms<int>::create_test_cyclic_list();
    list.create_cycle_at_index(2); // Create cycle at node with value 3

    REQUIRE(LinkedListAlgorithms<int>::detect_cycle_raw(list.get_head()));
  }

  SECTION("Cycle detection - without cycle") {
    auto list = LinkedListAlgorithms<int>::create_test_cyclic_list();
    // No cycle created

    REQUIRE_FALSE(LinkedListAlgorithms<int>::detect_cycle_raw(list.get_head()));
  }
}
