#include "08_dynamic_memory.h"
#include <stdexcept>

// Constructor
DynamicArray::DynamicArray(size_t initialSize) {
  // Your code here - allocate memory for 'initialSize' integers
}

// Destructor
DynamicArray::~DynamicArray() {
  // Your code here - free allocated memory
}

// Get element at index
int DynamicArray::get(size_t index) const {
  // Your code here - with bounds checking
  return 0; // Replace with correct implementation
}

// Set element at index
void DynamicArray::set(size_t index, int value) {
  // Your code here - with bounds checking
}

// Get current size
size_t DynamicArray::getSize() const { return size; }

// Resize the array
void DynamicArray::resize(size_t newSize) {
  // Your code here - allocate new memory and copy existing elements
}
