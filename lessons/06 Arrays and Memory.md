## Lesson 06: Arrays and Memory Basics

This lesson covers how arrays are organized in memory and basic memory manipulation:

### Memory Layout of Arrays

Arrays in C/C++ are stored as contiguous blocks of memory:

```
Array int arr[5] = {10, 20, 30, 40, 50};

Memory (assuming 4-byte integers):
Address:  1000    1004    1008    1012    1016
Values:   [10]    [20]    [30]    [40]    [50]
```

The name of the array (`arr`) is essentially a pointer to its first element. Array indexing is converted to pointer arithmetic:
- `arr[i]` is equivalent to `*(arr + i)`
- This means `arr[3]` is `*(arr + 3)`, which calculates the address as `base_address + (3 * sizeof(element))`

### C-style String Representation

A C-style string is an array of characters terminated by a null character (`\0`):

```
String "Hello"

Memory (1 byte per char):
Address:  1000    1001    1002    1003    1004    1005
Values:   ['H']   ['e']   ['l']   ['l']   ['o']   ['\0']
```

The null terminator is crucial - without it, functions wouldn't know where the string ends, leading to potential buffer overruns.

### Implementation of String Length Function

The `my_strlen` function demonstrates traversing memory:

```cpp
size_t my_strlen(const char *str) {
    const char *p = str;  // Start at beginning
    while (*p != '\0') {  // Keep going until null terminator
        p++;              // Move to next character
    }
    return p - str;       // Calculate distance traversed
}
```

This function:
1. Starts at the string's beginning
2. Increments a pointer until it finds the null terminator
3. Calculates the distance by pointer subtraction
4. Has O(n) time complexity where n is the string length

### String Copy and Memory Safety

The `my_strcpy` function demonstrates memory-to-memory copying:

```cpp
void my_strcpy(char *dst, const char *src) {
    while ((*dst++ = *src++) != '\0');
}
```

This compact code:
1. Copies each character from source to destination
2. Increments both pointers
3. Continues until it copies the null terminator (which becomes the loop termination condition)

**Memory Safety Issues**:
- No bounds checking - if the destination buffer is too small, it will overflow
- Can lead to buffer overruns, corrupting adjacent memory
- Modern alternatives like `strncpy` or `std::string` help prevent these issues

### Memory Alignment

Modern CPUs access memory most efficiently when data is properly aligned (starting at addresses that are multiples of the data size):

- 4-byte integers ideally start at addresses divisible by 4
- 8-byte doubles ideally start at addresses divisible by 8

Arrays automatically maintain proper alignment for their elements.
