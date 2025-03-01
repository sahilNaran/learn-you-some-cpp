#include "04_control_flow.h"
#include "catch.hpp"

TEST_CASE("Factorial calculations are correct", "[factorial]") {
  REQUIRE(factorial(0) == 1);
  REQUIRE(factorial(1) == 1);
  REQUIRE(factorial(5) == 120);
  REQUIRE(factorial(10) == 3628800);
  REQUIRE_THROWS_AS(factorial(-1), std::invalid_argument);
}

TEST_CASE("Grade converter using if-else statements works correctly",
          "[gradeConverter_if]") {
  REQUIRE(gradeConverter_if(95) == 'A');
  REQUIRE(gradeConverter_if(85) == 'B');
  REQUIRE(gradeConverter_if(75) == 'C');
  REQUIRE(gradeConverter_if(65) == 'D');
  REQUIRE(gradeConverter_if(55) == 'F');
  REQUIRE(gradeConverter_if(0) == 'F');
  REQUIRE(gradeConverter_if(100) == 'A');
  REQUIRE_THROWS_AS(gradeConverter_if(-1), std::invalid_argument);
  REQUIRE_THROWS_AS(gradeConverter_if(101), std::invalid_argument);
}

TEST_CASE("Grade converter using switch statement works correctly",
          "[gradeConverter_switch]") {
  REQUIRE(gradeConverter_switch(95) == 'A');
  REQUIRE(gradeConverter_switch(90) == 'A');
  REQUIRE(gradeConverter_switch(85) == 'B');
  REQUIRE(gradeConverter_switch(80) == 'B');
  REQUIRE(gradeConverter_switch(75) == 'C');
  REQUIRE(gradeConverter_switch(70) == 'C');
  REQUIRE(gradeConverter_switch(65) == 'D');
  REQUIRE(gradeConverter_switch(60) == 'D');
  REQUIRE(gradeConverter_switch(55) == 'F');
  REQUIRE(gradeConverter_switch(0) == 'F');
  REQUIRE(gradeConverter_switch(100) == 'A');
  REQUIRE_THROWS_AS(gradeConverter_switch(-1), std::invalid_argument);
  REQUIRE_THROWS_AS(gradeConverter_switch(101), std::invalid_argument);
}

TEST_CASE("Find first digit works correctly", "[findFirstDigit]") {
  REQUIRE(findFirstDigit(0) == 0);
  REQUIRE(findFirstDigit(5) == 5);
  REQUIRE(findFirstDigit(123) == 1);
  REQUIRE(findFirstDigit(9876) == 9);
  REQUIRE(findFirstDigit(-456) == 4);
}

TEST_CASE("Sum of odd digits works correctly", "[sumOddDigits]") {
  REQUIRE(sumOddDigits(0) == 0);
  REQUIRE(sumOddDigits(5) == 5);
  REQUIRE(sumOddDigits(2) == 0);
  REQUIRE(sumOddDigits(123) == 4);    // 1 + 3
  REQUIRE(sumOddDigits(2468) == 0);   // All even
  REQUIRE(sumOddDigits(13579) == 25); // All odd
  REQUIRE(sumOddDigits(-456) == 5);   // 5
}

TEST_CASE("Count digits in range works with different loop types",
          "[countDigitsInRange]") {
  SECTION("for loop") {
    REQUIRE(countDigitsInRange_for(0, 0, 9) == 1);
    REQUIRE(countDigitsInRange_for(12345, 1, 3) == 3); // 1, 2, 3
    REQUIRE(countDigitsInRange_for(12345, 6, 9) == 0); // None
    REQUIRE(countDigitsInRange_for(12345, 0, 9) == 5); // All
    REQUIRE(countDigitsInRange_for(-123, 1, 3) == 3);  // 1, 2, 3
  }

  SECTION("while loop") {
    REQUIRE(countDigitsInRange_while(0, 0, 9) == 1);
    REQUIRE(countDigitsInRange_while(12345, 1, 3) == 3); // 1, 2, 3
    REQUIRE(countDigitsInRange_while(12345, 6, 9) == 0); // None
    REQUIRE(countDigitsInRange_while(12345, 0, 9) == 5); // All
    REQUIRE(countDigitsInRange_while(-123, 1, 3) == 3);  // 1, 2, 3
  }

  SECTION("do-while loop") {
    REQUIRE(countDigitsInRange_dowhile(0, 0, 9) == 1);
    REQUIRE(countDigitsInRange_dowhile(12345, 1, 3) == 3); // 1, 2, 3
    REQUIRE(countDigitsInRange_dowhile(12345, 6, 9) == 0); // None
    REQUIRE(countDigitsInRange_dowhile(12345, 0, 9) == 5); // All
    REQUIRE(countDigitsInRange_dowhile(-123, 1, 3) == 3);  // 1, 2, 3
  }
}

TEST_CASE("FizzBuzz implementation works correctly", "[fizzBuzz_if]") {
  REQUIRE(fizzBuzz_if(1) == "1");
  REQUIRE(fizzBuzz_if(3) == "Fizz");
  REQUIRE(fizzBuzz_if(5) == "Buzz");
  REQUIRE(fizzBuzz_if(15) == "FizzBuzz");
  REQUIRE(fizzBuzz_if(30) == "FizzBuzz");
  REQUIRE(fizzBuzz_if(0) == "Invalid input");
  REQUIRE(fizzBuzz_if(-1) == "Invalid input");
}
