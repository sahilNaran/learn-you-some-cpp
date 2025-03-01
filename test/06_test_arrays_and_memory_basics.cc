#include "06_arrays_and_memory_basics.h"
#include "catch.hpp"

TEST_CASE("String utilities work correctly", "[strings]") {
  SECTION("String length") {
    REQUIRE(my_strlen("") == 0);
    REQUIRE(my_strlen("hello") == 5);
  }

  SECTION("String copy") {
    char dst[20] = {0};
    my_strcpy(dst, "test");
    REQUIRE(strcmp(dst, "test") == 0);
  }

  SECTION("String concatenation") {
    char dst[20] = "hello";
    my_strcat(dst, " world");
    REQUIRE(strcmp(dst, "hello world") == 0);
  }

  SECTION("Find character") {
    REQUIRE(my_find_char("hello", 'e') == 1);
    REQUIRE(my_find_char("hello", 'l') == 2);
    REQUIRE(my_find_char("hello", 'z') == -1);
  }
}
