#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdexcept>

template <typename T> class DoublyLinkedList {
private:
  struct Node {
    T data;
    Node *next;
    Node *prev;

    Node(const T &value) : data(value), next(nullptr), prev(nullptr) {}
  };

  Node *head;
  Node *tail;
  size_t size;

public:
  // Default constructor
  DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

  // Destructor
  ~DoublyLinkedList() {
    // Your code here - free all nodes
  }

  // Copy constructor
  DoublyLinkedList(const DoublyLinkedList &other)
      : head(nullptr), tail(nullptr), size(0) {
    // Your code here - deep copy from other
  }

  // Copy assignment operator
  DoublyLinkedList &operator=(const DoublyLinkedList &other) {
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

  // Insert at the end (tail)
  void push_back(const T &value) {
    // Your code here
  }

  // Remove from the end (tail)
  void pop_back() {
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

  // Access the last element
  T &back() {
    // Your code here - throw exception if empty
    if (!tail) {
      throw std::out_of_range("List is empty");
    }
    return tail->data;
  }

  const T &back() const {
    // Your code here - throw exception if empty
    if (!tail) {
      throw std::out_of_range("List is empty");
    }
    return tail->data;
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

  // Insert before the first occurrence of a value
  bool insert_before(const T &search_value, const T &new_value) {
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

  // Reverse the list
  void reverse() {
    // Your code here - reverse the list in-place
  }

  // Print the list forward (for debugging)
  void print_forward() const {
    // Your code here
  }

  // Print the list backward (for debugging)
  void print_backward() const {
    // Your code here
  }
};

#endif // DOUBLY_LINKED_LIST_H
