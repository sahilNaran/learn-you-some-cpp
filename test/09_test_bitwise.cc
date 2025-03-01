#include "09_bitwise.h"
#include "catch.hpp"

TEST_CASE("Bitwise operations work correctly", "[bitwise]") {
  SECTION("Bitwise AND") {
    REQUIRE(bitAnd(0b1100, 0b1010) == 0b1000);
    REQUIRE(bitAnd(0xFF, 0x0F) == 0x0F);
    REQUIRE(bitAnd(0, 255) == 0);
  }

  SECTION("Bitwise OR") {
    REQUIRE(bitOr(0b1100, 0b1010) == 0b1110);
    REQUIRE(bitOr(0xF0, 0x0F) == 0xFF);
    REQUIRE(bitOr(0, 0) == 0);
  }

  SECTION("Bitwise XOR") {
    REQUIRE(bitXor(0b1100, 0b1010) == 0b0110);
    REQUIRE(bitXor(0xFF, 0xFF) == 0);
    REQUIRE(bitXor(0, 255) == 255);
  }

  SECTION("Bitwise NOT") {
    REQUIRE(bitNot(0) == ~0);
    REQUIRE(bitNot(0xFF) == ~0xFF);
    REQUIRE((bitNot(bitNot(42)) == 42));
  }

  SECTION("Left Shift") {
    REQUIRE(leftShift(1, 3) == 8);
    REQUIRE(leftShift(0xFF, 4) == 0xFF0);
    REQUIRE(leftShift(0, 10) == 0);
  }

  SECTION("Right Shift") {
    REQUIRE(rightShift(8, 3) == 1);
    REQUIRE(rightShift(0xFF0, 4) == 0xFF);
    REQUIRE(rightShift(0, 10) == 0);
  }

  SECTION("Bit manipulation combinations") {
    REQUIRE(bitAnd(leftShift(1, 2), 0xFF) == 4);
    REQUIRE(bitOr(rightShift(0xFF0, 4), 0x00F) == 0xFF);
    REQUIRE(bitXor(leftShift(1, 3), rightShift(0x40, 1)) == 0b00101000);
  }
}
