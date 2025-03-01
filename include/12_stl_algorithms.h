#ifndef STL_ALGORITHMS_H
#define STL_ALGORITHMS_H
#include <vector>

std::vector<int> double_values(const std::vector<int> &nums);
bool all_positive(const std::vector<int> &nums);
int sum_elements(const std::vector<int> &nums);
void sort_by_second(std::vector<std::pair<std::string, int>> &pairs);
std::vector<int> filter_even(const std::vector<int> &nums);

#endif
