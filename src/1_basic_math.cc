#include "basic_math.h"
#include <stdexcept>

int add(int a, int b) { return a + b; }

int subtract(int a, int b) { return a - b; }

int multiply(int a, int b) { return a * b; }

double divide(double a, double b) {
  if (b == 0) {
    throw std::runtime_error("Division by zero");
  }
  return a / b;
}
