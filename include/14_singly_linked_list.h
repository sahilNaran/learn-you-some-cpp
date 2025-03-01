// singly_linked_list.h
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdexcept>

template <typename T> class SinglyLinkedList {
private:
  struct Node {
    T data;
    Node *next;

    Node(const T &value) : data(value), next(nullptr) {}
  };

  Node *head;
  size_t size;

public:
  // Default constructor
  SinglyLinkedList() : head(nullptr), size(0) {}

  // Destructor
  ~SinglyLinkedList() {
    // Your code here - free all nodes
  }

  // Copy constructor
  SinglyLinkedList(const SinglyLinkedList &other) : head(nullptr), size(0) {
    // Your code here - deep copy from other
  }

  // Copy assignment operator
  SinglyLinkedList &operator=(const SinglyLinkedList &other) {
    // Your code here - deep copy from other
    return *this;
  }

  // Get size
  size_t get_size() const { return size; }

  // Check if empty
  bool empty() const { return head == nullptr; }

  // Insert at the beginning (head)
  void push_front(const T &value) {
    // Your code here
  }

  // Remove from the beginning (head)
  void pop_front() {
    // Your code here - throw exception if empty
  }

  // Access the first element
  T &front() {
    // Your code here - throw exception if empty
    if (!head) {
      throw std::out_of_range("List is empty");
    }
    return head->data;
  }

  const T &front() const {
    // Your code here - throw exception if empty
    if (!head) {
      throw std::out_of_range("List is empty");
    }
    return head->data;
  }

  // Insert at the end
  void push_back(const T &value) {
    // Your code here
  }

  // Find value (return true if found, false otherwise)
  bool find(const T &value) const {
    // Your code here
    return false; // Replace with correct implementation
  }

  // Insert after the first occurrence of a value
  bool insert_after(const T &search_value, const T &new_value) {
    // Your code here - return false if search_value not found
    return false; // Replace with correct implementation
  }

  // Remove the first occurrence of a value
  bool remove(const T &value) {
    // Your code here - return false if value not found
    return false; // Replace with correct implementation
  }

  // Clear the list
  void clear() {
    // Your code here - remove all nodes
  }

  // Print the list (for debugging)
  void print() const {
    // Your code here
  }
};

#endif // SINGLY_LINKED_LIST_H
