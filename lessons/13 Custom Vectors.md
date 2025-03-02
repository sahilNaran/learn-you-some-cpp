## Lesson 13: Custom Vector Implementation

This lesson explores building a dynamic array container from scratch:

### Memory Management in Template Classes

Templates generate different code for each type they're instantiated with:

```cpp
template <typename T>
class MyVector {
    T *data;  // Points to dynamically allocated array of T
    // ... more members
};

// Usage:
MyVector<int> v1;       // Generates code for int version
MyVector<std::string> v2; // Generates different code for string version
```

The compiler creates a separate class for each type, with appropriate memory handling for that type's size and constructor/destructor requirements.

### Capacity Growth Strategy

When a vector needs to grow, it typically increases capacity by a factor:

```cpp
void push_back(const T &value) {
    if (size == capacity) {
        // Grow by a factor (typically 1.5 or 2)
        size_t new_capacity = capacity == 0 ? 1 : capacity * 2;
        reserve(new_capacity);
    }
    
    data[size++] = value;
}
```

This exponential growth strategy ensures:
- Amortized O(1) insertion at the end
- Minimizes the number of expensive resize operations
- Balances memory usage against reallocation costs

The tradeoff is some potential memory waste (up to 50% with a factor of 2).

### Copy Constructor and Assignment Operator

Proper resource management requires custom copy operations:

```cpp
// Copy constructor
MyVector(const MyVector &other) : data(nullptr), capacity(0), size(0) {
    if (other.size > 0) {
        // Allocate memory and copy elements
        data = new T[other.capacity];
        capacity = other.capacity;
        size = other.size;
        
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];  // Copy each element
        }
    }
}

// Copy assignment operator
MyVector &operator=(const MyVector &other) {
    if (this != &other) {  // Self-assignment check
        // Free existing resources
        delete[] data;
        
        // Copy from other (similar to copy constructor)
        // ...
    }
    return *this;
}
```

These implement **deep copying** - creating a completely independent copy with its own memory allocation.

### Iterator Implementation

Iterators provide a standard interface for traversing containers:

```cpp
class iterator {
private:
    T *ptr;  // Points to an element in the vector

public:
    iterator(T *p) : ptr(p) {}
    
    // Dereference - access the element
    T &operator*() { return *ptr; }
    
    // Pre-increment - advance to next element
    iterator &operator++() {
        ptr++;
        return *this;
    }
    
    // Post-increment
    iterator operator++(int) {
        iterator tmp = *this;
        ++(*this);
        return tmp;
    }
    
    // Comparison
    bool operator==(const iterator &other) const { return ptr == other.ptr; }
    bool operator!=(const iterator &other) const { return ptr != other.ptr; }
};
```

This lets the vector be used with standard loop constructs and algorithms:
```cpp
for (auto it = vec.begin(); it != vec.end(); ++it) {
    // Use *it to access each element
}
```

### Bounds Checking and Safety

The `at` method provides bounds checking:

```cpp
T &at(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}
```

This prevents buffer overruns at the cost of slightly lower performance compared to unchecked access.

### Insert and Erase Operations

Inserting or erasing elements in the middle requires shifting:

```cpp
iterator insert(iterator pos, const T &value) {
    size_t index = pos.ptr - data;  // Calculate position index
    
    if (size == capacity) {
        reserve(capacity == 0 ? 1 : capacity * 2);
        // pos is invalidated by reserve, recompute it
        pos = iterator(data + index);
    }
    
    // Shift elements to make space
    for (size_t i = size; i > index; i--) {
        data[i] = data[i-1];
    }
    
    // Insert the new element
    data[index] = value;
    size++;
    
    return iterator(data + index);
}
```

This has O(n) time complexity due to the shifting operation, compared to O(1) for push_back on average.
