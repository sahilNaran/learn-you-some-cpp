#include "01_basic_math.h"
#include <stdexcept>

// Adds two integers and returns their sum
int add(int a, int b) { return a + b; }

// Subtracts the second integer from the first and returns the difference
int subtract(int a, int b) { return a - b; }

// Multiplies two integers and returns their product
int multiply(int a, int b) { return a * b; }

// Divides the first number by the second and returns the quotient
// Throws a runtime_error if the second number is zero
double divide(double a, double b) {
  if (b == 0) {
    throw new std::runtime_error("Cannot divide by zero");
  }
  return a / b;
}
