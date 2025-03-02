## Lesson 10: Algorithm Basics - Searching

This lesson explores fundamental search algorithms and their efficiency:

### Linear Search Algorithm

Linear search sequentially checks each element:

```cpp
int linear_search(const int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;  // Found at index i
        }
    }
    return -1;  // Not found
}
```

**Time Complexity Analysis**:
- Best case: O(1) - element found at the first position
- Average case: O(n/2) = O(n) - on average, check half the elements
- Worst case: O(n) - element not present or at the last position
- Space complexity: O(1) - uses constant additional memory

### Binary Search Algorithm

Binary search exploits sorted data to eliminate half the remaining elements in each step:

```cpp
int binary_search(const int arr[], int size, int value) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Avoid overflow
        
        if (arr[mid] == value) {
            return mid;  // Found
        } else if (arr[mid] < value) {
            left = mid + 1;  // Look in right half
        } else {
            right = mid - 1;  // Look in left half
        }
    }
    
    return -1;  // Not found
}
```

**Time Complexity Analysis**:
- Best case: O(1) - element found at the middle
- Average and worst case: O(log n) - divide the search space in half with each step
- Space complexity: O(1) iterative version, O(log n) for recursive version (due to call stack)

**Why O(log n)**:
After each comparison, the search space is divided by 2:
n → n/2 → n/4 → ... → 1

The number of steps k needed to reach 1 is:
n / 2^k = 1
Solving for k: k = log₂(n)

### Efficient Counting in Sorted Arrays

For counting occurrences in a sorted array, we can use binary search to find boundaries:

```cpp
int count_occurrences_efficient(const int sorted_arr[], int size, int value) {
    // Find first occurrence
    int first = -1;
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sorted_arr[mid] == value) {
            first = mid;
            right = mid - 1;  // Continue searching left
        } else if (sorted_arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    if (first == -1) return 0;  // Not found
    
    // Find last occurrence
    int last = -1;
    left = 0;
    right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sorted_arr[mid] == value) {
            last = mid;
            left = mid + 1;  // Continue searching right
        } else if (sorted_arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return last - first + 1;  // Count = last index - first index + 1
}
```

**Time Complexity**: O(log n) for finding both boundaries, compared to O(n) for linear counting.

### Algorithm Performance Measurement

Comparing algorithm performance involves:

1. **Theoretical analysis**: Using Big O notation to predict asymptotic growth
2. **Empirical measurement**: Timing actual execution with large inputs

The difference between O(n) and O(log n) becomes dramatic as input size increases:

| Input size (n) | O(n) | O(log n) |
|----------------|------|----------|
| 10             | 10   | 3.3      |
| 100            | 100  | 6.6      |
| 1,000          | 1,000| 10       |
| 1,000,000      | 1,000,000 | 20  |

### Cache Considerations

Modern CPUs have a memory hierarchy with multiple cache levels:

1. **L1 cache**: Smallest but fastest (a few KB, ~1 ns access)
2. **L2 cache**: Larger but slower (a few hundred KB, ~3-10 ns)
3. **L3 cache**: Even larger but slower (a few MB, ~10-20 ns)
4. **Main memory (RAM)**: Much larger but much slower (GB, ~100 ns)

Linear search has better **spatial locality** (accessing adjacent memory locations) which can be more cache-friendly than binary search's jumping access pattern. This can sometimes make linear search faster for small arrays despite worse theoretical complexity.
