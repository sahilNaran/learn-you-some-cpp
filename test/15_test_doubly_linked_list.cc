#include "15_doubly_linked_list.h"
#include "catch.hpp"

TEST_CASE("DoublyLinkedList basics", "[doublylinkedlist]") {
  SECTION("Default constructor") {
    DoublyLinkedList<int> list;
    REQUIRE(list.empty());
    REQUIRE(list.get_size() == 0);
    REQUIRE_THROWS(list.front());
    REQUIRE_THROWS(list.back());
  }

  SECTION("push_front and front") {
    DoublyLinkedList<int> list;
    list.push_front(10);
    REQUIRE_FALSE(list.empty());
    REQUIRE(list.get_size() == 1);
    REQUIRE(list.front() == 10);
    REQUIRE(list.back() == 10);

    list.push_front(20);
    REQUIRE(list.get_size() == 2);
    REQUIRE(list.front() == 20);
    REQUIRE(list.back() == 10);
  }

  SECTION("push_back and back") {
    DoublyLinkedList<int> list;
    list.push_back(10);
    REQUIRE_FALSE(list.empty());
    REQUIRE(list.get_size() == 1);
    REQUIRE(list.front() == 10);
    REQUIRE(list.back() == 10);

    list.push_back(20);
    REQUIRE(list.get_size() == 2);
    REQUIRE(list.front() == 10);
    REQUIRE(list.back() == 20);
  }

  SECTION("pop_front") {
    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);

    list.pop_front();
    REQUIRE(list.get_size() == 1);
    REQUIRE(list.front() == 20);
    REQUIRE(list.back() == 20);

    list.pop_front();
    REQUIRE(list.empty());
    REQUIRE_THROWS(list.pop_front());
  }

  SECTION("pop_back") {
    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);

    list.pop_back();
    REQUIRE(list.get_size() == 1);
    REQUIRE(list.front() == 10);
    REQUIRE(list.back() == 10);

    list.pop_back();
    REQUIRE(list.empty());
    REQUIRE_THROWS(list.pop_back());
  }

  SECTION("find") {
    DoublyLinkedList<int> list;
    REQUIRE_FALSE(list.find(10));

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    REQUIRE(list.find(10));
    REQUIRE(list.find(20));
    REQUIRE(list.find(30));
    REQUIRE_FALSE(list.find(40));
  }

  SECTION("insert_after") {
    DoublyLinkedList<int> list;
    REQUIRE_FALSE(list.insert_after(10, 20));

    list.push_back(10);
    list.push_back(30);

    REQUIRE(list.insert_after(10, 20));
    REQUIRE(list.get_size() == 3);

    list.pop_front(); // Remove 10
    REQUIRE(list.front() == 20);
    REQUIRE(list.back() == 30);
  }

  SECTION("insert_before") {
    DoublyLinkedList<int> list;
    REQUIRE_FALSE(list.insert_before(30, 20));

    list.push_back(10);
    list.push_back(30);

    REQUIRE(list.insert_before(30, 20));
    REQUIRE(list.get_size() == 3);

    REQUIRE(list.front() == 10);
    list.pop_front(); // Remove 10
    REQUIRE(list.front() == 20);
    REQUIRE(list.back() == 30);
  }

  SECTION("remove") {
    DoublyLinkedList<int> list;
    REQUIRE_FALSE(list.remove(10));

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    REQUIRE(list.remove(20));
    REQUIRE(list.get_size() == 2);

    REQUIRE(list.front() == 10);
    REQUIRE(list.back() == 30);

    REQUIRE(list.remove(10));
    REQUIRE(list.front() == 30);
    REQUIRE(list.back() == 30);
    REQUIRE(list.get_size() == 1);

    REQUIRE(list.remove(30));
    REQUIRE(list.empty());
  }

  SECTION("clear") {
    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.clear();
    REQUIRE(list.empty());
    REQUIRE(list.get_size() == 0);
  }

  SECTION("reverse") {
    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.reverse();
    REQUIRE(list.front() == 30);
    REQUIRE(list.back() == 10);

    list.pop_front();
    REQUIRE(list.front() == 20);

    list.pop_back();
    REQUIRE(list.front() == 20);
    REQUIRE(list.back() == 20);
  }
}
