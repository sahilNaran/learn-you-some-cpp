#include "17_recursion.h"
#include "catch.hpp"
#include <iostream>

TEST_CASE("Basic recursive functions", "[recursion]") {
  SECTION("Factorial") {
    REQUIRE(factorial_recursion(0) == 1);
    REQUIRE(factorial_recursion(1) == 1);
    REQUIRE(factorial_recursion(5) == 120);
    REQUIRE(factorial_recursion(10) == 3628800);
    REQUIRE_THROWS(factorial_recursion(-1));
  }

  SECTION("Fibonacci") {
    REQUIRE(fibonacci(0) == 0);
    REQUIRE(fibonacci(1) == 1);
    REQUIRE(fibonacci(2) == 1);
    REQUIRE(fibonacci(3) == 2);
    REQUIRE(fibonacci(4) == 3);
    REQUIRE(fibonacci(5) == 5);
    REQUIRE(fibonacci(10) == 55);
    REQUIRE_THROWS(fibonacci(-1));
  }

  SECTION("Sum of digits") {
    REQUIRE(sum_of_digits(0) == 0);
    REQUIRE(sum_of_digits(9) == 9);
    REQUIRE(sum_of_digits(123) == 6);
    REQUIRE(sum_of_digits(9876) == 30);
  }

  SECTION("Palindrome check") {
    REQUIRE(is_palindrome(""));
    REQUIRE(is_palindrome("a"));
    REQUIRE(is_palindrome("racecar"));
    REQUIRE(is_palindrome("madam"));
    REQUIRE(is_palindrome("abba"));
    REQUIRE_FALSE(is_palindrome("hello"));
    REQUIRE_FALSE(is_palindrome("algorithm"));
  }

  SECTION("Power function") {
    REQUIRE(power(2, 0) == 1);
    REQUIRE(power(2, 3) == 8);
    REQUIRE(power(3, 2) == 9);
    REQUIRE(power(5, 3) == 125);
    REQUIRE(power(2, -2) == 0.25);
    REQUIRE(power(4, -1) == 0.25);
  }
}

TEST_CASE("Fibonacci performance", "[recursion][!benchmark]") {
  // This is an optional benchmark to demonstrate the inefficiency of naive
  // recursion

  auto start = std::chrono::high_resolution_clock::now();
  fibonacci(30); // This should be slow with a naive implementation
  auto end = std::chrono::high_resolution_clock::now();

  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count();
  std::cout << "Fibonacci(30) took " << duration << " ms" << std::endl;

  // No assertion here, just observing performance
}
