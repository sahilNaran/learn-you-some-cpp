## Lesson 07: Pointers and References

This lesson explores core memory addressing mechanisms in C++:

### Memory Addresses and Pointers

A pointer is a variable that stores a memory address:

```
int x = 42;        // Regular variable
int *p = &x;       // Pointer to x

Memory:
Address:  1000       1004
Values:   [42]       [1000]
Variable: x          p
```

The pointer `p` contains the address of `x` (1000 in this example), not its value.

### Pointer Dereferencing

The `*` operator (when used on a pointer) dereferences it, accessing the value at the memory address:

```cpp
int x = 42;
int *p = &x;
*p = 100;  // Changes x to 100 by writing to its memory location
```

You can visualize this as "following the arrow" to access the target:

```
Memory:
┌───────────────┐      ┌───────────────┐
│ Variable: p   │      │ Variable: x   │
│ Address: 1004 │      │ Address: 1000 │
│ Value: 1000   │─────▶│ Value: 42     │
└───────────────┘      └───────────────┘

After *p = 100:
┌───────────────┐      ┌───────────────┐
│ Variable: p   │      │ Variable: x   │
│ Address: 1004 │      │ Address: 1000 │
│ Value: 1000   │─────▶│ Value: 100    │
└───────────────┘      └───────────────┘
```

When dereferencing occurs, the CPU:
1. Retrieves the memory address stored in the pointer
2. Uses that address to access the target memory location
3. Reads from or writes to that location

### References vs. Pointers

References are like pointers but with important differences:

1. References must be initialized when declared
2. References cannot be reassigned to refer to different objects
3. References don't need dereferencing syntax
4. References cannot be null

Implementation-wise, references are typically pointers under the hood, but with different semantics enforced by the compiler:

```cpp
int x = 5;
int &r = x;    // Reference to x
int *p = &x;   // Pointer to x

r = 10;        // Directly modifies x
*p = 10;       // Same effect, but requires dereferencing
```

### Pass by Value vs. Pass by Reference

Parameter passing mechanisms differ in how they handle memory:

**Pass by Value**:
- Creates a copy of the argument
- Changes to the parameter don't affect the original variable
- Requires enough stack space for the entire object

**Pass by Reference**:
- Passes a reference (effectively a pointer) to the original
- Changes to the parameter affect the original variable
- Only requires stack space for the reference (typically 4 or 8 bytes)

```
Function: void increment(int &x) { x++; }

When called with: increment(number)

Stack frame:
+-------------------+
| Return address    |
+-------------------+
| Reference to      | --> Points to original 'number' variable
| 'number'          |     in the caller's memory space
+-------------------+
```

### Swap Implementation Analysis

The swap functions demonstrate pass by reference and pointer mechanisms:

```cpp
void swap_ptr(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_ref(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
```

Both functions:
1. Create a temporary copy of one value
2. Overwrite the first value with the second
3. Set the second value to the saved temporary

Memory operations are identical - the difference is in syntax and safety constraints.

### Array Access via Pointers

The `reverse_array` function demonstrates pointer-based array traversal:

```cpp
void reverse_array(int arr[], int size) {
    int *start = arr;
    int *end = arr + size - 1;
    
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
```

This algorithm:
1. Sets pointers to the first and last elements
2. Swaps elements at these positions
3. Moves pointers toward the center
4. Continues until they meet or cross

The time complexity is O(n/2), which simplifies to O(n).
