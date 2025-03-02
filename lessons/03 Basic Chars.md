## Lesson 03: Character Operations

This lesson delves into how computers represent and manipulate individual characters:

### ASCII and Unicode Representation

Characters in computers are represented as numeric codes:

**ASCII (American Standard Code for Information Interchange)**:
- Uses 7 bits, representing 128 different characters
- Range: 0-127
- Examples: 'A' is 65, 'a' is 97, '0' is 48

```
ASCII Table Structure:
0-31: Control characters (non-printable)
32-47: Punctuation and symbols
48-57: Digits 0-9
65-90: Uppercase letters A-Z
97-122: Lowercase letters a-z
```

The ASCII design intentionally places uppercase and lowercase letters 32 positions apart (2^5), allowing case conversion by flipping a single bit:
```
'A' (65 in decimal, 01000001 in binary)
'a' (97 in decimal, 01100001 in binary)
                     ^
                     Bit position 5 differs
```

**Unicode**:
- Extends ASCII to support international characters
- UTF-8 encoding uses 1-4 bytes per character
- UTF-16 uses 2 or 4 bytes per character

### Bit-Level Character Operations

Case conversion can be implemented with bitwise operations:

```cpp
// To uppercase (clear bit 5)
char toUpperChar(char c) {
    return c & ~(1 << 5);  // Clear bit at position 5
}

// To lowercase (set bit 5)
char toLowerChar(char c) {
    return c | (1 << 5);   // Set bit at position 5
}
```

### Character Classification Implementation

Functions like `isDigit()` can be implemented through range checks or lookup tables:

1. **Range check method**:
```cpp
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}
```

2. **Lookup table method**:
```cpp
// Pre-computed table of 128 boolean values
static const bool digitTable[128] = { /* values */ };

bool isDigit(char c) {
    return (c >= 0 && c < 128) ? digitTable[c] : false;
}
```

Lookup tables trade memory for speed, offering O(1) classification by using the character's numeric value as an array index.

### Efficiency Considerations

Character operations are typically very fast because:
- They operate on small fixed-size data (usually 1 byte)
- Many operations can be implemented with simple bit manipulations
- Modern CPUs have specialized instructions for common character operations
- Character lookup tables fit entirely in CPU cache
