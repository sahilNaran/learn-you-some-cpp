#include "06_arrays_and_memory_basics.h"

size_t my_strlen(const char *str) {
  const char *currentCharacter = str;
  while (*currentCharacter != '\0') {
    currentCharacter++;
  }
  return currentCharacter - str;
}

// Copy src to dst (don't use std::strcpy!)
void my_strcpy(char *dst, const char *src) {
  while (*src != '\0') {
    *dst = *src;
    dst++;
    src++;
  }
  *dst = '\0';
}

// Concatenate src to dst (don't use std::strcat!)
void my_strcat(char *dst, const char *src) {
  while (*dst != '\0') {
    dst++;
  }
  my_strcpy(dst, src);
  /*while (*src != '\0') {*/
  /*  *dst = *src;*/
  /*  dst++;*/
  /*  src++;*/
  /*}*/
  /**dst = '\0';*/
}

// Find character in string, return index or -1 if not found
int my_find_char(const char *str, char c) {
  const char *start = str;
  while (*str != '\0') {
    if (*str == c) {
      return str - start;
    }
    str++;
  }

  return -1;

  // Solution above uses pointer arithmetic
  //
  /*int index = 0;*/
  /*while (*str != '\0') {*/
  /*  if (*str == c) {*/
  /*    return index;*/
  /*  }*/
  /*  index++;*/
  /*  str++;*/
  /*}*/
  /*return -1;*/
}
