#ifndef DYNAMIC_MEMORY_H
#define DYNAMIC_MEMORY_H

#include <cstddef> // For size_t

class DynamicArray {
private:
  int *data;
  size_t size;

public:
  // Constructor
  DynamicArray(size_t initialSize);

  // Destructor
  ~DynamicArray();

  // Get element at index
  int get(size_t index) const;

  // Set element at index
  void set(size_t index, int value);

  // Get current size
  size_t getSize() const;

  // Resize the array
  void resize(size_t newSize);
};

#endif // DYNAMIC_ARRAY_H
