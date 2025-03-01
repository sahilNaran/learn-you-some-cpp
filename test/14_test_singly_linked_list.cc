#include "14_singly_linked_list.h"
#include "catch.hpp"

TEST_CASE("SinglyLinkedList basics", "[singlylinkedlist]") {
  SECTION("Default constructor") {
    SinglyLinkedList<int> list;
    REQUIRE(list.empty());
    REQUIRE(list.get_size() == 0);
    REQUIRE_THROWS(list.front());
  }

  SECTION("push_front and front") {
    SinglyLinkedList<int> list;
    list.push_front(10);
    REQUIRE_FALSE(list.empty());
    REQUIRE(list.get_size() == 1);
    REQUIRE(list.front() == 10);

    list.push_front(20);
    REQUIRE(list.get_size() == 2);
    REQUIRE(list.front() == 20);
  }

  SECTION("pop_front") {
    SinglyLinkedList<int> list;
    list.push_front(10);
    list.push_front(20);

    list.pop_front();
    REQUIRE(list.get_size() == 1);
    REQUIRE(list.front() == 10);

    list.pop_front();
    REQUIRE(list.empty());
    REQUIRE_THROWS(list.pop_front());
  }

  SECTION("push_back") {
    SinglyLinkedList<int> list;
    list.push_back(10);
    REQUIRE(list.get_size() == 1);
    REQUIRE(list.front() == 10);

    list.push_back(20);
    REQUIRE(list.get_size() == 2);

    list.pop_front();
    REQUIRE(list.front() == 20);
  }

  SECTION("find") {
    SinglyLinkedList<int> list;
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
    SinglyLinkedList<int> list;
    REQUIRE_FALSE(list.insert_after(10, 20));

    list.push_back(10);
    list.push_back(30);

    REQUIRE(list.insert_after(10, 20));
    REQUIRE(list.get_size() == 3);

    list.pop_front(); // Remove 10
    REQUIRE(list.front() == 20);

    list.pop_front(); // Remove 20
    REQUIRE(list.front() == 30);
  }

  SECTION("remove") {
    SinglyLinkedList<int> list;
    REQUIRE_FALSE(list.remove(10));

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    REQUIRE(list.remove(20));
    REQUIRE(list.get_size() == 2);

    list.pop_front(); // Remove 10
    REQUIRE(list.front() == 30);

    REQUIRE(list.remove(30));
    REQUIRE(list.empty());

    REQUIRE_FALSE(list.remove(30));
  }

  SECTION("clear") {
    SinglyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.clear();
    REQUIRE(list.empty());
    REQUIRE(list.get_size() == 0);
  }
}

TEST_CASE("SinglyLinkedList copy semantics", "[singlylinkedlist]") {
  SECTION("Copy constructor") {
    SinglyLinkedList<int> list1;
    list1.push_back(10);
    list1.push_back(20);
    list1.push_back(30);

    SinglyLinkedList<int> list2(list1);
    REQUIRE(list2.get_size() == 3);

    // Check list2 contents
    REQUIRE(list2.front() == 10);
    list2.pop_front();
    REQUIRE(list2.front() == 20);
    list2.pop_front();
    REQUIRE(list2.front() == 30);

    // Modify list2 and check that list1 is unchanged
    list2.clear();
    REQUIRE(list2.empty());
    REQUIRE_FALSE(list1.empty());
    REQUIRE(list1.get_size() == 3);
  }

  SECTION("Copy assignment operator") {
    SinglyLinkedList<int> list1;
    list1.push_back(10);
    list1.push_back(20);

    SinglyLinkedList<int> list2;
    list2.push_back(30);

    list2 = list1;
    REQUIRE(list2.get_size() == 2);

    // Check list2 contents
    REQUIRE(list2.front() == 10);
    list2.pop_front();
    REQUIRE(list2.front() == 20);

    // Modify list2 and check that list1 is unchanged
    list2.clear();
    REQUIRE(list2.empty());
    REQUIRE_FALSE(list1.empty());
    REQUIRE(list1.get_size() == 2);
  }
}
