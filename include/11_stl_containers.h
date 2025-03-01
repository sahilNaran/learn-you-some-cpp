#ifndef STL_CONTAINERS_H
#define STL_CONTAINERS_H
#include <map>
#include <string>
#include <vector>

int most_frequent(const std::vector<int> &nums);
std::vector<int> remove_duplicates(const std::vector<int> &nums);
std::map<std::string, int> count_words(const std::vector<std::string> &words);
std::vector<int> find_intersection(const std::vector<int> &nums1,
                                   const std::vector<int> &nums2);

#endif
