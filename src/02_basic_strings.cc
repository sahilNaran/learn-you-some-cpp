#include "02_basic_strings.h"
#include <algorithm>
#include <cctype>

// Concatenates two strings together
// Returns a new string that is the combination of s1 followed by s2
std::string concatenate(const std::string &s1, const std::string &s2) {
  return s1 + s2;
}

// Extracts a portion of a string
// Returns a new string that contains 'length' characters from 's' starting at
// position 'start' If 'start' is beyond the end of the string or 'length' is
// zero, returns an empty string
std::string substring(const std::string &s, size_t start, size_t length) {
  return s.substr(start, length);
}

// Checks if a string contains a substring
// Returns true if 'substring' is found within 's', false otherwise
// Special case: if substring equals s, should return true
bool contains(const std::string &s, const std::string &substring) {
  if (s.length() == substring.length()) {
    return s == substring;
  }
  return s.find(substring);
}

// Converts all characters in a string to uppercase
// Returns a new string with all lowercase letters converted to uppercase
std::string toUpper(const std::string &s) {
  std::string upper = s;
  std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
  return upper;
}

// Converts all characters in a string to lowercase
// Returns a new string with all uppercase letters converted to lowercase
std::string toLower(const std::string &s) {
  std::string lower = s;
  std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
  return lower;
}

// Finds the first occurrence of a character in a string
// Returns the index of the first occurrence of 'c' in 's'
size_t findFirstOf(const std::string &s, char c) { return s.find_first_of(c); }

// Replaces all occurrences of a substring with another string
// Returns a new string where every occurrence of 'from' in 's' is replaced with
// 'to'
std::string replace(const std::string &s, const std::string &from,
                    const std::string &to) {
  std::string result = s;
  int pos = 0;

  while ((pos = result.find(from, pos)) != std::string::npos) {
    result.replace(pos, from.length(), to);
    pos += to.length();
  }

  return result;
}
