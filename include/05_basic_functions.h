#ifndef BASIC_FUNCTIONS_H
#define BASIC_FUNCTIONS_H

namespace temperature {
double to_fahrenheit(double celsius);
double to_celsius(double fahrenheit);
bool is_freezing(double temp, bool is_celsius = true);
} // namespace temperature
#endif
