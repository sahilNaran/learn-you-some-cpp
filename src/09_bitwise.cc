#include "09_bitwise.h"

// Performs bitwise AND operation on two integers
int bitAnd(int a, int b) { return a & b; }

// Performs bitwise OR operation on two integers
int bitOr(int a, int b) { return a | b; }

// Performs bitwise XOR operation on two integers
// Returns the result of a ^ b
int bitXor(int a, int b) { return a ^ b; }

// Performs bitwise NOT operation on an integer
int bitNot(int a) { return ~a; }

// Performs left shift operation on an integer
int leftShift(int a, int shift) { return a << shift; }

// Performs right shift operation on an integer
int rightShift(int a, int shift) { return a >> shift; }
