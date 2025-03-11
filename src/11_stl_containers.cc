#include "11_stl_containers.h"
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>

int most_frequent(const std::vector<int> &nums) {
  std::unordered_map<int, int> frequency;

  for (int num : nums) {
    frequency[num] = frequency[num] + 1; // default value is 0
  }

  int max_count = 0;
  int result = 0;
  for (const auto &pair : frequency) {
    if (pair.second > max_count) {
      max_count = pair.second;
      result = pair.first;
    }
  }

  return result;
}

// Remove duplicates from a vector, preserving order
std::vector<int> remove_duplicates(const std::vector<int> &nums) {
  std::vector<int> result;
  std::unordered_set<int> seenNumbers;

  for (int num : nums) {
    if (seenNumbers.find(num) == seenNumbers.end()) {
      result.push_back(num);
      seenNumbers.insert(num);
    }
  }

  return result;
}

// Implement a word frequency counter
std::map<std::string, int> count_words(const std::vector<std::string> &words) {
  std::map<std::string, int> result;

  for (std::string word : words) {
    result[word] = result[word] + 1; // default is 0
  }

  return result;
}

// Find common elements between two vectors
std::vector<int> find_intersection(const std::vector<int> &nums1,
                                   const std::vector<int> &nums2) {
  std::set<int> set1(nums1.begin(), nums1.end());
  std::vector<int> result;

  for (int num : nums2) {
    if (set1.count(num) > 0) {
      result.push_back(num);
      set1.erase(num);
    }
  }

  return result;
}
