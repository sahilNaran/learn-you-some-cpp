## Lesson 02: String Operations

This lesson explores how strings are managed in memory and the implications of various string operations:

### String Memory Layout

In C++, a `std::string` is a complex object that manages:

1. A **pointer** to a dynamically allocated character array
2. The **size** of the string (number of characters)
3. The **capacity** of the allocated memory

```
Memory representation of std::string "Hello":

String object (on stack):
+-------------------+
| ptr to char array | -----> Heap memory:
+-------------------+         +---+---+---+---+---+---+
| size (5)          |         | H | e | l | l | o | \0|
+-------------------+         +---+---+---+---+---+---+
| capacity (e.g., 8)|
+-------------------+
```

Many implementations use **Small String Optimization (SSO)** where short strings are stored directly in the string object rather than on the heap to improve performance.

### Reference Parameters and Memory Efficiency

When passing strings as arguments, using `const std::string &` (reference) instead of `std::string` (by value) avoids creating copies:

```cpp
// Inefficient - creates a copy of the entire string
void processString(std::string s);

// Efficient - no copy is made, just references the original
void processString(const std::string &s);
```

At the memory level, a reference is implemented as a pointer to the original object, but with safer semantics. The `const` qualifier prevents accidental modification.

### String Concatenation and Memory Allocation

When concatenating strings, new memory must be allocated to hold the result:

1. The system checks if the first string has enough capacity
2. If not, it allocates a new, larger memory block (typically 1.5 or 2 times the required size)
3. It copies both strings into this new memory
4. It updates the string object to point to the new memory block

This process involves **dynamic memory allocation**, which is relatively slow compared to other operations.

### Substring Extraction Time Complexity

When calling `substring`, a new string is created with its own memory:

1. Memory is allocated for the new string
2. The specified characters are copied from the original string
3. The new string object is configured to point to this memory

This is an O(n) operation where n is the length of the substring, as it requires copying each character.

### String Search Algorithms

Finding a substring within a string can be implemented using various algorithms:

1. **Naive approach**: Check each position - O(nm) where n is the string length and m is the pattern length
2. **Knuth-Morris-Pratt (KMP)**: Avoids redundant comparisons - O(n+m)
3. **Boyer-Moore**: Skips sections of text - can be better than O(n) in practice
4. **Rabin-Karp**: Uses hashing - average case O(n+m)

Most C++ standard library implementations use optimized versions of these algorithms.
