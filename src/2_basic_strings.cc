#include "basic_strings.h"
#include <algorithm>
#include <cctype>

std::string concatenate(const std::string &s1, const std::string &s2) {
  return s1 + s2;
}

std::string substring(const std::string &s, size_t start, size_t length) {
  return s.substr(start, length);
}

bool contains(const std::string &s, const std::string &substring) {
  if (s.length() == substring.length()) {
    return s == substring;
  }
  return s.find(substring);
}

std::string toUpper(const std::string &s) {
  std::string result(s.size(), ' ');
  std::transform(s.begin(), s.end(), result.begin(), ::toupper);
  return result;
}

std::string toLower(const std::string &s) {
  std::string result(s.size(), ' ');
  std::transform(s.begin(), s.end(), result.begin(), ::tolower);
  return result;
}

size_t findFirstOf(const std::string &s, char c) { return s.find_first_of(c); }

std::string replace(const std::string &s, const std::string &from,
                    const std::string &to) {
  std::string result = s;
  size_t pos = 0;

  while ((pos = result.find(from, pos)) != std::string::npos) {
    result.replace(pos, from.length(), to);
    pos += to.length();
  }
  return result;
}
