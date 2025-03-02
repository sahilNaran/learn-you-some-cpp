## Lesson 12: STL Algorithms

This lesson examines the Standard Template Library's algorithmic components and how they enable powerful abstractions:

### Generic Programming Paradigm

STL algorithms demonstrate **generic programming** - writing code that works with any type satisfying certain requirements:

```cpp
// Works with any container with random access iterators
template<typename Container>
void sort_container(Container& c) {
    std::sort(c.begin(), c.end());
}
```

The compiler generates specialized code for each type used, combining safety with performance.

### Iterator Model

Iterators abstract the process of traversing containers:

```
Different iterator types:
- Input iterator: Forward reading only (e.g., std::istream_iterator)
- Output iterator: Forward writing only (e.g., std::ostream_iterator)
- Forward iterator: Forward traversal, reading and writing
- Bidirectional iterator: Forward and backward traversal
- Random access iterator: Constant-time access to any element
```

Iterator operations include:
- `++it` - Move to next element
- `*it` - Access the element
- `it1 == it2` - Compare iterators
- `it1 != it2` - Test inequality

### Transformation Operation Implementation

The `double_values` function demonstrates the transformation pattern:

```cpp
std::vector<int> double_values(const std::vector<int> &nums) {
    std::vector<int> result(nums.size());
    std::transform(nums.begin(), nums.end(), result.begin(),
                   [](int x) { return x * 2; });
    return result;
}
```

Under the hood, `std::transform` is essentially:
```cpp
template<typename InputIt, typename OutputIt, typename UnaryOperation>
OutputIt transform(InputIt first, InputIt last, OutputIt d_first, 
                  UnaryOperation op) {
    while (first != last) {
        *d_first++ = op(*first++);
    }
    return d_first;
}
```

This provides cleaner, more maintainable code than explicit loops while maintaining performance.

### Predicate-Based Algorithms

The `all_positive` function uses a predicate-testing algorithm:

```cpp
bool all_positive(const std::vector<int> &nums) {
    return std::all_of(nums.begin(), nums.end(), 
                       [](int x) { return x > 0; });
}
```

Implementation of `std::all_of` is conceptually:
```cpp
template<typename InputIt, typename UnaryPredicate>
bool all_of(InputIt first, InputIt last, UnaryPredicate p) {
    while (first != last) {
        if (!p(*first++)) {
            return false;
        }
    }
    return true;
}
```

This early-return approach stops at the first failing element, potentially saving significant computation.

### Accumulation Algorithms

The `sum_elements` function demonstrates reduction operations:

```cpp
int sum_elements(const std::vector<int> &nums) {
    return std::accumulate(nums.begin(), nums.end(), 0);
}
```

Implementation of `std::accumulate`:
```cpp
template<typename InputIt, typename T>
T accumulate(InputIt first, InputIt last, T init) {
    while (first != last) {
        init = init + *first++; // May use operator+ or a custom function
    }
    return init;
}
```

This pattern generalizes to other fold/reduce operations common in functional programming.

### Custom Sorting Criteria

The `sort_by_second` function demonstrates sorting with custom comparators:

```cpp
void sort_by_second(std::vector<std::pair<std::string, int>> &pairs) {
    std::sort(pairs.begin(), pairs.end(),
              [](const auto &a, const auto &b) {
                  return a.second > b.second; // Descending order
              });
}
```

The sorting algorithm (typically introsort - a hybrid of quicksort, heapsort, and insertion sort) uses the comparator to determine element ordering:
- Returns true if first argument should come before second
- Must define a strict weak ordering (transitive, irreflexive, antisymmetric)

### Filter Pattern Implementation

The `filter_even` function demonstrates filtering elements:

```cpp
std::vector<int> filter_even(const std::vector<int> &nums) {
    std::vector<int> result;
    std::copy_if(nums.begin(), nums.end(), std::back_inserter(result),
                 [](int x) { return x % 2 == 0; });
    return result;
}
```

Key components:
- `std::copy_if` selects elements meeting a condition
- `std::back_inserter` creates an output iterator that calls `push_back` on the container
- The lambda function defines the filter condition

This approach separates the filtering logic from container management.
