#ifndef BACKTRACKING_H
#define BACKTRACKING_H
#include <vector>

std::vector<std::string> permutations(const std::string &str);
std::vector<std::vector<int>> subsets(const std::vector<int> &nums);
std::vector<int> n_queens(int n);
bool sudoku(std::vector<std::vector<int>> &board);

#endif
