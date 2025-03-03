#include "04_control_flow.h"
#include <cstdint>
#include <stdexcept>
#include <string>

// Calculates the factorial of a non-negative integer
// Returns n! = n * (n-1) * (n-2) * ... * 2 * 1
// Returns 1 for n=0 (0! = 1 by definition)
unsigned long long factorial(int n) {
  if (n < 0) {
    throw std::invalid_argument("n must be non-negative");
  }

  if (n == 0) {
    return 1;
  }

  uint64_t factorial = 1;
  for (int i = n; i > 0; i--) {
    factorial *= i;
  }
  return factorial;
}

// Converts a numerical score to a letter grade using if statements
// 90-100: 'A', 80-89: 'B', 70-79: 'C', 60-69: 'D', below 60: 'F'
char gradeConverter_if(int score) {
  if (score >= 90 && score <= 100) {
    return 'A';
  }

  if (score >= 80 && score <= 89) {
    return 'B';
  }

  if (score >= 70 && score <= 79) {

    return 'C';
  }

  if (score >= 60 && score <= 69) {
    return 'D';
  }

  if (score >= 0 && score <= 60) {
    return 'F';
  }

  throw std::invalid_argument("Score must be between 1 and 100");
}

// Converts a numerical score to a letter grade using a switch statement
// 90-100: 'A', 80-89: 'B', 70-79: 'C', 60-69: 'D', below 60: 'F'
char gradeConverter_switch(int score) {
  if (score < 0 || score > 100) {
    throw std::invalid_argument("Score must be between 0 and 100");
  }

  switch (score / 10) {
  case 10:
  case 9:
    return 'A';
  case 8:
    return 'B';
  case 7:
    return 'C';
  case 6:
    return 'D';
  default:
    return 'F';
  }
}

// Finds and returns the first digit of a number
// For example: 1234 returns 1, 567 returns 5, -890 returns 8
int findFirstDigit(int number) {
  if (number < 0) {
    number = number * -1;
  }

  while (number > 0) {
    if (number < 10) {
      return number;
    }
    number = number / 10;
  }

  return 0;
}

// Calculates the sum of all odd digits in a number
// For example: 1234 returns 1+3=4, 567 returns 5+7=12
int sumOddDigits(int number) {
  if (number < 0) {
    number = number * -1;
  }

  int sum = 0;
  while (number > 0) {
    int digit = number % 10;
    if (digit % 2 != 0) {
      sum += digit;
    }
    number = number / 10;
  }

  return sum;
}

// Counts digits in a number that fall within the specified range [min, max]
// Implemented using a for loop
int countDigitsInRange_for(int number, int min, int max) {
  if (number < 0) {
    number = number * -1;
  }

  if (number == 0) {
    return (number >= min && number <= max) ? 1 : 0;
  }

  int numOfDigits = 0;
  for (; number > 0; number = number / 10) {
    int digit = number % 10;
    if (digit >= min && digit <= max) {
      numOfDigits++;
    }
  }
  return numOfDigits;
}

// Counts digits in a number that fall within the specified range [min, max]
// Implemented using a while loop
int countDigitsInRange_while(int number, int min, int max) {
  if (number < 0) {
    number = number * -1;
  }

  if (number == 0) {
    return (number >= min && number <= max) ? 1 : 0;
  }

  int numOfDigits = 0;
  while (number > 0) {
    int digit = number % 10;
    if (digit >= min && digit <= max) {
      numOfDigits++;
    }
    number = number / 10;
  }

  return numOfDigits;
}

// Counts digits in a number that fall within the specified range [min, max]
// Implemented using a do-while loop
int countDigitsInRange_dowhile(int number, int min, int max) {
  if (number < 0) {
    number = number * -1;
  }

  if (number == 0) {
    return (number >= min && number <= max) ? 1 : 0;
  }

  int numOfDigits = 0;
  do {
    int digit = number % 10;
    if (digit >= min && digit <= max) {
      numOfDigits++;
    }
    number = number / 10;
  } while (number > 0);

  return numOfDigits;
}

// Implements the FizzBuzz game for a single number using if statements
// Returns "Fizz" if number is divisible by 3
// Returns "Buzz" if number is divisible by 5
// Returns "FizzBuzz" if number is divisible by both 3 and 5
// Returns the number as a string otherwise
std::string fizzBuzz_if(int number) {
  if (number % 5 == 0 && number % 3 == 0) {
    return "FizzBuzz";
  }
  if (number % 3 == 0) {
    return "Fizz";
  }
  if (number % 5 == 0) {
    return "Buzz";
  }
  return std::to_string(number);
}
