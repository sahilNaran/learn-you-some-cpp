#ifndef CUSTOM_VECTORS_H
#define CUSTOM_VECTORS_H

#include <cstddef>
#include <stdexcept>

template <typename T> class MyVector {
private:
  T *data;
  size_t capacity;
  size_t size;

  // Helper function to resize the internal array
  void resize_capacity(size_t new_capacity) {
    // Your code here
  }

public:
  // Iterator class
  class iterator {
  private:
    T *ptr;

  public:
    iterator(T *p) : ptr(p) {}

    // Iterator operators
    T &operator*() { return *ptr; }
    iterator &operator++() {
      ptr++;
      return *this;
    }
    iterator operator++(int) {
      iterator tmp = *this;
      ++(*this);
      return tmp;
    }
    bool operator==(const iterator &other) const { return ptr == other.ptr; }
    bool operator!=(const iterator &other) const { return ptr != other.ptr; }
    iterator operator+(int n) { return iterator(ptr + n); }
  };

  // Default constructor
  MyVector() : data(nullptr), capacity(0), size(0) {
    // Your code here - initialize with capacity 0
  }

  // Constructor with initial capacity
  explicit MyVector(size_t initial_capacity)
      : data(nullptr), capacity(0), size(0) {
    // Your code here - allocate memory for initial_capacity elements
  }

  // Destructor
  ~MyVector() {
    // Your code here - free allocated memory
  }

  // Copy constructor
  MyVector(const MyVector &other) : data(nullptr), capacity(0), size(0) {
    // Your code here - deep copy from other
  }

  // Copy assignment operator
  MyVector &operator=(const MyVector &other) {
    // Your code here - deep copy from other
    return *this;
  }

  // Element access
  T &at(size_t index) {
    // Your code here - with bounds checking
    if (index >= size) {
      throw std::out_of_range("Index out of range");
    }
    return data[index];
  }

  const T &at(size_t index) const {
    // Your code here - with bounds checking
    if (index >= size) {
      throw std::out_of_range("Index out of range");
    }
    return data[index];
  }

  T &operator[](size_t index) {
    // Your code here - no bounds checking
    return data[index];
  }

  const T &operator[](size_t index) const {
    // Your code here - no bounds checking
    return data[index];
  }

  // Capacity
  bool empty() const {
    // Your code here
    return size == 0;
  }

  size_t get_size() const {
    // Your code here
    return size;
  }

  size_t get_capacity() const {
    // Your code here
    return capacity;
  }

  void reserve(size_t new_capacity) {
    // Your code here - increase capacity if needed
  }

  // Modifiers
  void push_back(const T &value) {
    // Your code here - add element to the end
  }

  void pop_back() {
    // Your code here - remove last element
  }

  void clear() {
    // Your code here - remove all elements
  }

  iterator insert(iterator pos, const T &value) {
    // Your code here - insert element at position
    return iterator(nullptr); // Replace with correct implementation
  }

  iterator erase(iterator pos) {
    // Your code here - remove element at position
    return iterator(nullptr); // Replace with correct implementation
  }

  // Iterators
  iterator begin() {
    // Your code here
    return iterator(data);
  }

  iterator end() {
    // Your code here
    return iterator(data + size);
  }
};

#endif // MY_VECTOR_H
