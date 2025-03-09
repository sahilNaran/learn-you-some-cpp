#include "08_dynamic_memory.h"
#include <stdexcept>

// Constructor
DynamicArray::DynamicArray(size_t initialSize) {
  data = new int[initialSize];
  size = initialSize;
}

// Destructor
DynamicArray::~DynamicArray() { delete[] data; }

// Get element at index
int DynamicArray::get(size_t index) const {
  if (index < 0 || index > size - 1) {
    throw std::out_of_range("index out of bounds");
  }
  return data[index];
}

// Set element at index
void DynamicArray::set(size_t index, int value) {
  if (index < 0 || index > size - 1) {
    throw std::out_of_range("index out of bounds");
  }
  data[index] = value;
}

// Get current size
size_t DynamicArray::getSize() const { return size; }

// Resize the array
void DynamicArray::resize(size_t newSize) {
  int *newData = new int[newSize];

  size_t copySize = (newSize < size) ? newSize : size;

  for (int i = 0; i < copySize; i++) {
    newData[i] = data[i];
  }

  delete[] data;
  data = newData;
  size = newSize;
}
