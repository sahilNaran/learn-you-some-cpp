#ifndef BASIC_STRING_H
#define BASIC_STRING_H
#include <cstddef>
#include <string>

std::string concatenate(const std::string &s1, const std::string &s2);
std::string substring(const std::string &s, size_t start, size_t length);
bool contains(const std::string &s, const std::string &substring);
std::string toUpper(const std::string &s);
std::string toLower(const std::string &s);
size_t findFirstOf(const std::string &s, char c);
std::string replace(const std::string &s, const std::string &from,
                    const std::string &to);

#endif
