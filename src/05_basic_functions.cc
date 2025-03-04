#include "05_basic_functions.h"

namespace temperature {

// Converts a temperature from Celsius to Fahrenheit
double to_fahrenheit(double celsius) { return celsius * 9.0 / 5.0 + 32.0; }

// Converts a temperature from Fahrenheit to Celsius
double to_celsius(double fahrenheit) { return (fahrenheit - 32) * 5 / 9; }

// Determines if a temperature is at or below freezing point
// For Celsius, freezing is at 0°C
// For Fahrenheit, freezing is at 32°F
bool is_freezing(double temp, bool is_celsius) {
  if (is_celsius) {
    return temp <= 0;
  }
  return temp <= 32.0;
}

} // namespace temperature
