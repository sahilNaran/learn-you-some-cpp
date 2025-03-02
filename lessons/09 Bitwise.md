## Lesson 09: Bitwise Operations

This lesson explores manipulating data at the individual bit level:

### Binary Representation of Integers

Integers are stored as sequences of bits:

```
Decimal 42 in 8-bit binary: 00101010

Bit position:  7  6  5  4  3  2  1  0
Bit value:     0  0  1  0  1  0  1  0
Weight (2^n): 128 64 32 16  8  4  2  1
```

Each bit position represents a power of 2, and the sum of all set bits gives the decimal value.

### Two's Complement for Negative Numbers

Signed integers use two's complement representation:

```
Decimal -42 in 8-bit two's complement:

1. Positive 42:    00101010
2. Flip all bits:  11010101
3. Add 1:          11010110  (-42 in two's complement)
```

Benefits of two's complement:
- Addition and subtraction work identically for positive and negative numbers
- No special handling needed for sign in basic arithmetic operations
- Only one representation of zero (unlike sign-magnitude)
- The most significant bit acts as the sign bit (0 for positive, 1 for negative)

### Bitwise Operators Implementation

Bitwise operations are implemented directly in CPU hardware:

**AND (&)**: Sets a bit in the result if the corresponding bits in both operands are 1
```
  10110110
& 10011100
----------
  10010100
```

**OR (|)**: Sets a bit in the result if at least one of the corresponding bits in the operands is 1
```
  10110110
| 10011100
----------
  10111110
```

**XOR (^)**: Sets a bit in the result if exactly one of the corresponding bits in the operands is 1
```
  10110110
^ 10011100
----------
  00101010
```

**NOT (~)**: Flips all bits
```
~ 10110110
----------
  01001001
```

### Bit Shifts

Shift operations move bits left or right:

**Left Shift (<<)**: Shifts bits left, filling with zeros from the right
```
00001011 << 2 = 00101100
```
Left shifting by n positions multiplies the value by 2^n (if no overflow).

**Right Shift (>>)**: Shifts bits right, filling with zeros (for unsigned) or sign bit (for signed)
```
10110000 >> 3 = 00010110  (unsigned)
10110000 >> 3 = 11110110  (signed, preserving the sign bit)
```
Right shifting by n positions divides the value by 2^n (integer division).

### Bit Manipulation Applications

Bitwise operations enable efficient implementations of various operations:

1. **Checking if a bit is set**:
```cpp
bool isBitSet(int value, int position) {
    return (value & (1 << position)) != 0;
}
```

2. **Setting a bit**:
```cpp
int setBit(int value, int position) {
    return value | (1 << position);
}
```

3. **Clearing a bit**:
```cpp
int clearBit(int value, int position) {
    return value & ~(1 << position);
}
```

4. **Toggling a bit**:
```cpp
int toggleBit(int value, int position) {
    return value ^ (1 << position);
}
```

### Bitmasks and Flags

Bitmasks allow multiple boolean flags to be stored efficiently in a single integer:

```cpp
// Define flags as powers of 2
const int READ_PERMISSION = 0x4;    // 100 in binary
const int WRITE_PERMISSION = 0x2;   // 010 in binary
const int EXECUTE_PERMISSION = 0x1; // 001 in binary

// Combining flags with OR
int permissions = READ_PERMISSION | WRITE_PERMISSION; // 110 in binary

// Checking flags with AND
bool canRead = (permissions & READ_PERMISSION) != 0;    // true
bool canWrite = (permissions & WRITE_PERMISSION) != 0;  // true
bool canExecute = (permissions & EXECUTE_PERMISSION) != 0; // false
```

This technique is used extensively in systems programming, hardware interfaces, and performance-critical code.
