#ifndef LINKED_LIST_ALGORITHMS_H
#define LINKED_LIST_ALGORITHMS_H

#include "14_singly_linked_list.h"
#include <stdexcept>

template <typename T> class LinkedListAlgorithms {
private:
  // Helper class for cycle detection exercise
  class CyclicLinkedList {
  private:
    struct Node {
      T data;
      Node *next;

      Node(const T &value) : data(value), next(nullptr) {}
    };

    Node *head;
    Node *cycle_point;

  public:
    CyclicLinkedList() : head(nullptr), cycle_point(nullptr) {}

    ~CyclicLinkedList() {
      if (!head)
        return;

      // Break the cycle before deleting
      if (cycle_point) {
        Node *temp = head;
        while (temp->next != cycle_point) {
          temp = temp->next;
        }
        temp->next = nullptr;
      }

      // Delete all nodes
      Node *current = head;
      while (current) {
        Node *temp = current;
        current = current->next;
        delete temp;
      }
    }

    void add_node(const T &value) {
      Node *new_node = new Node(value);

      if (!head) {
        head = new_node;
        return;
      }

      Node *temp = head;
      while (temp->next) {
        temp = temp->next;
      }
      temp->next = new_node;
    }

    void create_cycle_at_index(int index) {
      if (!head)
        return;

      // Find node at index
      Node *target = head;
      for (int i = 0; i < index && target->next; i++) {
        target = target->next;
      }

      // Find the last node
      Node *last = head;
      while (last->next) {
        last = last->next;
      }

      // Create cycle
      last->next = target;
      cycle_point = target;
    }

    Node *get_head() const { return head; }
    // Add this line right here, after the public members but still inside the
    // CyclicLinkedList class
    friend class LinkedListAlgorithms;
  };

public:
  // Detect if a linked list has a cycle
  static bool has_cycle(const SinglyLinkedList<T> &list) {
    // This doesn't work because SinglyLinkedList doesn't expose its nodes
    // In a real implementation, you'd need a different approach
    // For interview practice, implement this conceptually:

    /*
    Algorithm (Floyd's Cycle-Finding Algorithm):
    1. Use two pointers: slow and fast
    2. Move slow by 1 step, fast by 2 steps
    3. If they meet, there's a cycle
    4. If fast reaches null, there's no cycle
    */

    // Placeholder return for compilation
    return false;
  }

  // Find middle element of a linked list
  static T find_middle(const SinglyLinkedList<T> &list) {
    // Your code here - use two pointers (slow and fast)
    if (list.empty()) {
      throw std::runtime_error("List is empty");
    }

    // Placeholder implementation - replace with proper algorithm
    SinglyLinkedList<T> copy = list;
    size_t mid_index = list.get_size() / 2;

    for (size_t i = 0; i < mid_index; i++) {
      copy.pop_front();
    }

    return copy.front();
  }

  // Helper for test - detect cycle in raw linked list
  static bool detect_cycle_raw(typename CyclicLinkedList::Node *head) {
    // Your code here - implement Floyd's cycle detection algorithm

    // Using void* to avoid template issues with the test
    void *slow = head;
    void *fast = head;

    while (slow != nullptr && fast != nullptr) {
      // Cast to Node* for operations
      slow = static_cast<typename CyclicLinkedList::Node *>(slow)->next;

      fast = static_cast<typename CyclicLinkedList::Node *>(fast)->next;
      if (fast != nullptr) {
        fast = static_cast<typename CyclicLinkedList::Node *>(fast)->next;
      }

      if (slow == fast && slow != nullptr) {
        return true;
      }
    }

    return false;
  }

  // Create a cyclic list for testing
  static CyclicLinkedList create_test_cyclic_list() {
    CyclicLinkedList list;
    list.add_node(1);
    list.add_node(2);
    list.add_node(3);
    list.add_node(4);
    list.add_node(5);
    return list;
  }
};

#endif // LINKED_LIST_ALGORITHMS_H
