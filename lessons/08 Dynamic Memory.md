## Lesson 08: Dynamic Memory Management

This lesson explores how programs allocate and manage memory at runtime:

### Memory Regions: Stack vs. Heap

Modern computer programs use different memory regions:

**Stack**:
- Managed automatically by the compiler
- LIFO (Last-In-First-Out) structure
- Fixed size, determined at program start
- Fast allocation and deallocation
- Stores local variables, function parameters, and return addresses
- Memory is automatically reclaimed when functions return

**Heap**:
- Managed explicitly by the programmer (`new`/`delete` in C++)
- No particular structure or order
- Size limited by available system memory
- Slower allocation than stack
- Persists until explicitly freed
- Can suffer from fragmentation over time

```
Memory layout of a running program:
+------------------+  High addresses
| Command line     |
| arguments & env  |
+------------------+
| Stack            | ← Grows downward
|                  |
+------------------+
|        ↑         |
|        |         |  Free memory
|        ↓         |
+------------------+
| Heap             | ← Grows upward
|                  |
+------------------+
| Uninitialized    |
| data (BSS)       |
+------------------+
| Initialized data |
+------------------+
| Program code     |  Low addresses
+------------------+
```

### Dynamic Memory Allocation Mechanics

The `DynamicArray` constructor demonstrates heap allocation:

```cpp
DynamicArray::DynamicArray(size_t initialSize) {
    data = new int[initialSize];  // Allocate memory on heap
    size = initialSize;
}
```

What happens when `new` is called:
1. The memory allocator (often `malloc` underneath) searches for a free block of sufficient size
2. It marks that block as used in its internal data structures
3. It returns a pointer to the allocated memory
4. The constructor initializes the object at that memory location

### Memory Deallocation and Memory Leaks

The destructor ensures memory is properly released:

```cpp
DynamicArray::~DynamicArray() {
    delete[] data;  // Release allocated memory
}
```

When `delete[]` is called:
1. Object destructors are called for each array element
2. The memory block is marked as free in the allocator's data structures
3. The memory becomes available for future allocations

**Memory Leaks** occur when allocated memory is never freed:
- The pointer to the memory is lost (e.g., overwritten or goes out of scope)
- The memory remains allocated but is inaccessible
- Over time, this reduces available memory for the program
- In long-running programs, memory leaks can cause system slowdowns or crashes

### Array Resizing Strategy

The `resize` method demonstrates dynamic array growth:

```cpp
void DynamicArray::resize(size_t newSize) {
    int *newData = new int[newSize];  // Allocate new array
    
    // Copy elements from old to new array
    size_t copySize = (newSize < size) ? newSize : size;
    for (size_t i = 0; i < copySize; i++) {
        newData[i] = data[i];
    }
    
    delete[] data;        // Free old array
    data = newData;       // Update pointer
    size = newSize;       // Update size
}
```

This process involves:
1. Allocating a new, larger block of memory
2. Copying existing elements to the new block
3. Deallocating the old memory block
4. Updating the pointer to reference the new memory

### Amortized Analysis of Dynamic Arrays

Consider how vectors typically grow:
- When full, capacity often increases by a factor (commonly 1.5 or 2)
- This resizing is expensive (O(n) for copying n elements)
- But it happens infrequently (after n, n/2, n/4... insertions)

**Amortized time** analysis distributes this cost:
- n insertions require approximately 2n operations total
- This averages to O(1) per insertion (amortized constant time)
- Without this growth strategy, each insertion would require a resize, resulting in O(n²) performance

This demonstrates how algorithmic design choices significantly impact performance.
