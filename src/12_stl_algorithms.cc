#include "12_stl_algorithms.h"
#include <algorithm>
#include <iterator>
#include <numeric>

// Transform a vector of integers by doubling each value
std::vector<int> double_values(const std::vector<int> &nums) {
  std::vector<int> result(nums.size());
  std::transform(nums.begin(), nums.end(), result.begin(),
                 [](int x) { return x * 2; });
  return result;
}

// Check if all elements in the vector satisfy a condition (are positive)
bool all_positive(const std::vector<int> &nums) {
  return std::all_of(nums.begin(), nums.end(), [](int x) { return x > 0; });
}

// Find the sum of all elements in the vector
int sum_elements(const std::vector<int> &nums) {
  return std::accumulate(nums.begin(), nums.end(), 0);
}

// Sort a vector of pairs by the second element (descending)
void sort_by_second(std::vector<std::pair<std::string, int>> &pairs) {
  std::sort(pairs.begin(), pairs.end(),
            [](const auto &a, const auto &b) { return a.second > b.second; });
}

// Filter a vector to include only even numbers
std::vector<int> filter_even(const std::vector<int> &nums) {
  std::vector<int> result;
  std::copy_if(nums.begin(), nums.end(), std::back_inserter(result),
               [](int x) { return x % 2 == 0; });
  return result;
}
