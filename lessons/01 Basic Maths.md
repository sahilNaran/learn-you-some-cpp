## Lesson 01: Basic Math Operations

This lesson covers fundamental arithmetic operations, exploring how computers actually handle these calculations:

### Binary Representation and Arithmetic

At the hardware level, integers are stored as binary (base-2) numbers. When adding two numbers, the CPU's **Arithmetic Logic Unit (ALU)** performs binary addition:

```
  1101 (13 in decimal)
+ 0110 ( 6 in decimal)
------
 10011 (19 in decimal)
```

This process happens with **carry bits** propagating from right to left, just like in decimal addition. The CPU implements this using logic gates - specifically combinations of **half adders** and **full adders**.

### Two's Complement Representation

Negative integers are typically represented using **two's complement** notation:

1. Take the binary representation of the positive number
2. Flip all the bits (0s become 1s and vice versa)
3. Add 1 to the result

For example, -6 in an 8-bit two's complement system:
```
 6 in binary:  00000110
Flip all bits: 11111001
Add 1:         11111010 (represents -6)
```

Two's complement elegantly allows the same addition circuits to work for both addition and subtraction, as subtracting a number is equivalent to adding its negative (two's complement) representation.

### Integer Overflow

C++ integers have fixed sizes (typically 32 or 64 bits), which means they can represent a limited range of values. When a calculation produces a result outside this range, **integer overflow** occurs:

```
In an 8-bit unsigned integer:
255 + 1 = 0  (overflows and wraps around)

In an 8-bit signed integer:
127 + 1 = -128  (overflows and wraps to negative)
```

The CPU typically sets an **overflow flag** when this happens, but C++ doesn't automatically check this flag, making overflow a potential source of bugs.

### Floating-Point Numbers

Floating-point numbers (like `double`) follow the **IEEE 754** standard, representing numbers in scientific notation as:

±(1.fraction) × 2^exponent

For a 32-bit float:
- 1 bit for the sign
- 8 bits for the exponent (stored with a bias of 127)
- 23 bits for the fraction (with an implicit leading 1)

This representation allows for a wide range of values but introduces **rounding errors** because not all decimal numbers can be represented exactly in binary.

### Division Implementation

Division is more complex than addition or multiplication. The CPU typically implements it using algorithms like:

1. **Repeated subtraction** (inefficient)
2. **Shift-and-subtract** algorithms
3. **Newton-Raphson approximation** for floating-point division

Division by zero is undefined in mathematics and typically triggers an exception or produces a special value like `Infinity` in floating-point calculations.
