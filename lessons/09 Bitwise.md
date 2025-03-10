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

### Number Representation in Code
In C++ and many other programming languages, numbers can be represented in different formats:

1. **Decimal Notation**: The standard base-10 representation we use every day.
   - Example: `42`, `255`, `1024`

2. **Binary Notation (0b prefix)**: Explicitly represents the binary bits.
   - Example: `0b1010` (decimal 10), `0b11111111` (decimal 255)
   - Each digit is either 0 or 1, representing individual bits
   - The `0b` prefix tells the compiler this is a binary number

3. **Hexadecimal Notation (0x prefix)**: Base-16 representation, using digits 0-9 and A-F.
   - Example: `0xFF` (decimal 255), `0x1A` (decimal 26)
   - Each hex digit represents exactly 4 binary bits
   - The `0x` prefix tells the compiler this is a hexadecimal number

Converting between these formats:
- `0xFF` = `0b11111111` = decimal 255
- `0x0F` = `0b00001111` = decimal 15
- `42` = `0b00101010` = `0x2A`

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
Shift operations move bits left or right within a binary representation, changing the value in predictable ways:

**Left Shift (<<)**: Shifts all bits to the left by the specified number of positions, filling vacated positions with zeros from the right.
```
Example: 00001011 << 2 = 00101100

Initial value:  0 0 0 0 1 0 1 1  (decimal 11)
                ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑
                7 6 5 4 3 2 1 0  (bit positions)

After shift:    0 0 1 0 1 1 0 0  (decimal 44)
                ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑
                7 6 5 4 3 2 1 0  (bit positions)
```
Notice that each bit moved 2 positions to the left, and zeros filled in from the right. The leftmost bits (positions 6 and 7) were "shifted out" and discarded.

Left shifting by n positions mathematically multiplies the value by 2^n (as long as no significant bits are lost):
- 11 (decimal) << 2 = 11 × 2^2 = 11 × 4 = 44

**Right Shift (>>)**: Shifts all bits to the right by the specified number of positions. What fills the vacated positions depends on whether the number is signed or unsigned:

For unsigned integers, zeros fill in from the left:
```
Example: 10110000 >> 3 = 00010110  (unsigned)

Initial value:  1 0 1 1 0 0 0 0  (decimal 176)
                ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑
                7 6 5 4 3 2 1 0  (bit positions)

After shift:    0 0 0 1 0 1 1 0  (decimal 22)
                ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑
                7 6 5 4 3 2 1 0  (bit positions)
```

For signed integers (two's complement), the sign bit (leftmost bit) is replicated to preserve the sign:
```
Example: 10110000 >> 3 = 11110110  (signed)

Initial value:  1 0 1 1 0 0 0 0  (negative in two's complement)
                ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑
                7 6 5 4 3 2 1 0  (bit positions)

After shift:    1 1 1 1 0 1 1 0  (still negative)
                ↑ ↑ ↑ ↑ ↑ ↑ ↑ ↑
                7 6 5 4 3 2 1 0  (bit positions)
```

This behavior, where the sign bit is copied, is called an "arithmetic right shift" and preserves the sign of the number.

Right shifting by n positions mathematically divides the value by 2^n (with truncation toward zero):
- 176 (unsigned) >> 3 = 176 ÷ 2^3 = 176 ÷ 8 = 22

Bit shifts are extremely efficient at the hardware level and are commonly used for:
- Fast multiplication and division by powers of 2
- Isolating specific bits in a value (combined with masks)
- Packing and unpacking data in constrained environments
- Low-level hardware control where specific bit patterns are required

### Bit Manipulation Applications
Bitwise operations enable efficient implementations of various operations:

1. **Checking if a bit is set**:
```cpp
bool isBitSet(int value, int position) {
    return (value & (1 << position)) != 0;
}
```
This function works by:
- Creating a mask with only the bit at `position` set to 1: `(1 << position)`
- Using AND to compare this mask with the original value
- If the result is non-zero, the bit was set; otherwise, it was not

Example:
```
value = 00101010, position = 3
mask = 1 << 3 = 00001000
00101010 & 00001000 = 00001000 (non-zero, so bit is set)

value = 00101010, position = 0
mask = 1 << 0 = 00000001
00101010 & 00000001 = 00000000 (zero, so bit is not set)
```

2. **Setting a bit**:
```cpp
int setBit(int value, int position) {
    return value | (1 << position);
}
```
This function works by:
- Creating a mask with only the bit at `position` set to 1: `(1 << position)`
- Using OR to combine this mask with the original value
- Since 1 OR x = 1 (for any x), the bit at that position becomes 1

Example:
```
value = 00101010, position = 0
mask = 1 << 0 = 00000001
00101010 | 00000001 = 00101011 (bit at position 0 is now set)
```

3. **Clearing a bit**:
```cpp
int clearBit(int value, int position) {
    return value & ~(1 << position);
}
```
This function works by:
- Creating a mask with only the bit at `position` set to 1: `(1 << position)`
- Inverting this mask using NOT: `~(1 << position)` (all bits are 1 except position)
- Using AND to apply this inverted mask to the original value
- Since 0 AND x = 0 (for any x), the bit at that position becomes 0

Example:
```
value = 00101010, position = 3
mask = 1 << 3 = 00001000
inverted mask = ~00001000 = 11110111
00101010 & 11110111 = 00100010 (bit at position 3 is now cleared)
```

4. **Toggling a bit**:
```cpp
int toggleBit(int value, int position) {
    return value ^ (1 << position);
}
```
This function works by:
- Creating a mask with only the bit at `position` set to 1: `(1 << position)`
- Using XOR to apply this mask to the original value
- Since 1 XOR 0 = 1 and 1 XOR 1 = 0, the bit at that position flips its state

Example:
```
value = 00101010, position = 3
mask = 1 << 3 = 00001000
00101010 ^ 00001000 = 00100010 (bit at position 3 flipped from 1 to 0)

value = 00101010, position = 1
mask = 1 << 1 = 00000010
00101010 ^ 00000010 = 00101000 (bit at position 1 flipped from 0 to 1)
```

### Practical Examples with Different Notations

Here are examples showing how the same operations work with different number notations:

**AND operation**:
```
Binary:       0b1100 & 0b1010 = 0b1000
Hexadecimal:  0xFF & 0x0F = 0x0F
Decimal:      12 & 10 = 8
```

**OR operation**:
```
Binary:       0b1100 | 0b1010 = 0b1110
Hexadecimal:  0xF0 | 0x0F = 0xFF
Decimal:      12 | 10 = 14
```

**XOR operation**:
```
Binary:       0b1100 ^ 0b1010 = 0b0110
Hexadecimal:  0xFF ^ 0xFF = 0x00
Decimal:      12 ^ 10 = 6
```

**Left Shift**:
```
Binary:       0b0001 << 3 = 0b1000
Hexadecimal:  0x01 << 3 = 0x08
Decimal:      1 << 3 = 8
```

**Right Shift**:
```
Binary:       0b1000 >> 3 = 0b0001
Hexadecimal:  0x08 >> 3 = 0x01
Decimal:      8 >> 3 = 1
```

These examples demonstrate how bitwise operations function identically regardless of which notation you use to represent the numbers.

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
