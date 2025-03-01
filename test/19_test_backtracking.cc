#include "19_backtracking.h"
#include "catch.hpp"
#include <algorithm> // for std::sort
#include <set>
#include <string>
#include <vector>

TEST_CASE("Backtracking algorithms", "[backtracking]") {
  SECTION("String permutations") {
    std::vector<std::string> perms1 = permutations("abc");
    std::sort(perms1.begin(), perms1.end());

    std::vector<std::string> expected1 = {"abc", "acb", "bac",
                                          "bca", "cab", "cba"};
    REQUIRE(perms1 == expected1);

    // Empty string
    std::vector<std::string> perms2 = permutations("");
    REQUIRE(perms2.size() == 1);
    REQUIRE(perms2[0] == "");

    // String with duplicate characters
    std::vector<std::string> perms3 = permutations("aab");
    // Remove duplicates
    std::set<std::string> unique_perms(perms3.begin(), perms3.end());
    REQUIRE(unique_perms.size() == 3);
    REQUIRE(unique_perms.count("aab") == 1);
    REQUIRE(unique_perms.count("aba") == 1);
    REQUIRE(unique_perms.count("baa") == 1);
  }

  SECTION("Subsets") {
    std::vector<std::vector<int>> subs1 = subsets({1, 2, 3});
    REQUIRE(subs1.size() == 8); // 2^3 = 8 subsets

    // Check that empty set is included
    bool has_empty = false;
    for (const auto &subset : subs1) {
      if (subset.empty()) {
        has_empty = true;
        break;
      }
    }
    REQUIRE(has_empty);

    // Check that the original set is included
    bool has_full = false;
    for (const auto &subset : subs1) {
      if (subset.size() == 3 &&
          std::find(subset.begin(), subset.end(), 1) != subset.end() &&
          std::find(subset.begin(), subset.end(), 2) != subset.end() &&
          std::find(subset.begin(), subset.end(), 3) != subset.end()) {
        has_full = true;
        break;
      }
    }
    REQUIRE(has_full);

    // Empty set
    std::vector<std::vector<int>> subs2 = subsets({});
    REQUIRE(subs2.size() == 1);
    REQUIRE(subs2[0].empty());
  }

  SECTION("N-Queens") {
    // 1-Queens is trivial
    std::vector<int> board1 = n_queens(1);
    REQUIRE(board1.size() == 1);
    REQUIRE((board1[0] >= 0 && board1[0] < 1));

    // 4-Queens has solutions
    std::vector<int> board4 = n_queens(4);
    REQUIRE(board4.size() == 4);

    // Verify solution
    bool valid = true;
    for (int i = 0; i < 4; i++) {
      for (int j = i + 1; j < 4; j++) {
        // Check if queens attack each other
        if (board4[i] == board4[j] || // Same column
            std::abs(board4[i] - board4[j]) ==
                std::abs(i - j)) { // Same diagonal
          valid = false;
          break;
        }
      }
    }
    REQUIRE(valid);

    // 3-Queens has no solutions
    std::vector<int> board3 = n_queens(3);
    REQUIRE(board3.empty());
  }

  SECTION("Sudoku") {
    std::vector<std::vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0}, {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0}, {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1}, {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0}, {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    REQUIRE(sudoku(board));

    // Verify solution
    bool valid = true;

    // Check rows
    for (int row = 0; row < 9; row++) {
      std::vector<bool> seen(10, false);
      for (int col = 0; col < 9; col++) {
        int num = board[row][col];
        if (num < 1 || num > 9 || seen[num]) {
          valid = false;
          break;
        }
        seen[num] = true;
      }
    }

    // Check columns
    for (int col = 0; col < 9; col++) {
      std::vector<bool> seen(10, false);
      for (int row = 0; row < 9; row++) {
        int num = board[row][col];
        if (num < 1 || num > 9 || seen[num]) {
          valid = false;
          break;
        }
        seen[num] = true;
      }
    }

    // Check 3x3 boxes
    for (int box_row = 0; box_row < 3; box_row++) {
      for (int box_col = 0; box_col < 3; box_col++) {
        std::vector<bool> seen(10, false);
        for (int row = box_row * 3; row < (box_row + 1) * 3; row++) {
          for (int col = box_col * 3; col < (box_col + 1) * 3; col++) {
            int num = board[row][col];
            if (num < 1 || num > 9 || seen[num]) {
              valid = false;
              break;
            }
            seen[num] = true;
          }
        }
      }
    }

    REQUIRE(valid);
  }
}
