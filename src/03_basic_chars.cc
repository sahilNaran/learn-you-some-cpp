#include "03_basic_chars.h"

// Determines if a character is a digit (0-9)
// Returns true if the character is between '0' and '9', false otherwise
bool isDigit(char c) { return c >= '0' && c <= '9'; }

// Determines if a character is an alphabetic character (a-z, A-Z)
// Returns true if the character is a letter, false otherwise
bool isAlpha(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Determines if a character is either alphabetic or numeric
// Returns true if the character is a letter or digit, false otherwise
bool isAlphaNum(char c) { return isDigit(c) || isAlpha(c); }

// Determines if a character is a lowercase letter (a-z)
// Returns true if the character is between 'a' and 'z', false otherwise
bool isLower(char c) { return c >= 'a' && c <= 'z'; }

// Determines if a character is an uppercase letter (A-Z)
// Returns true if the character is between 'A' and 'Z', false otherwise
bool isUpper(char c) { return c >= 'A' && c <= 'Z'; }

// Converts a lowercase letter to uppercase
// If the character is already uppercase or not a letter, returns it unchanged
char toUpperChar(char c) {
  if (c >= 'a' && c <= 'z') {
    return c - 32;
  }
  return c;
}

// Converts an uppercase letter to lowercase
// If the character is already lowercase or not a letter, returns it unchanged
char toLowerChar(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c + 32;
  }
  return c;
}
