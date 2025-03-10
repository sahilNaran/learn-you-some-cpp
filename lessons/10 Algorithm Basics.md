## Lesson 10: Algorithm Basics - Searching

This lesson explores fundamental search algorithms and their efficiency. These are essential tools that will help you solve many programming problems!

### Linear Search Algorithm

Linear search is the simplest search algorithm - it checks each element one-by-one from start to finish, like flipping through pages in a book until you find what you're looking for.

```
Linear Search for value 7:
Array: [3, 9, 4, 7, 6, 2, 1, 8, 5]

Step 1: Check 3 == 7? No → continue
   [3, 9, 4, 7, 6, 2, 1, 8, 5]
    ^
Step 2: Check 9 == 7? No → continue
   [3, 9, 4, 7, 6, 2, 1, 8, 5]
       ^
Step 3: Check 4 == 7? No → continue
   [3, 9, 4, 7, 6, 2, 1, 8, 5]
          ^
Step 4: Check 7 == 7? Yes! → return index 3
   [3, 9, 4, 7, 6, 2, 1, 8, 5]
             ^
Found at index 3!
```

```cpp
int linear_search(const int arr[], int size, int value) {
    // Loop through each element in the array
    for (int i = 0; i < size; i++) {
        // Check if the current element matches what we're looking for
        if (arr[i] == value) {
            return i;  // Found at index i! Return the position
        }
    }
    return -1;  // Checked entire array and didn't find it
}
```

**How It Works:**
1. Start at the beginning (index 0)
2. Compare the current element with the value you're looking for
3. If it matches, you're done! Return the current position
4. If not, move to the next element and repeat
5. If you reach the end without finding the value, return -1

**Time Complexity Analysis** (how the algorithm's running time grows with input size):
- **Best case**: O(1) - This means "constant time." It happens when the element is at the very first position, so we only need one comparison!
- **Average case**: O(n/2) = O(n) - On average, we check half the elements before finding what we're looking for. The O(n) means the time grows linearly with the input size.
- **Worst case**: O(n) - This happens when the element is at the last position or not present at all. We have to check every single element!
- **Space complexity**: O(1) - The algorithm uses the same amount of extra memory regardless of input size (just a few variables).

**When to use linear search:**
- When your data is unsorted
- When your list is small
- When you're only searching once (not repeatedly)
- When your data structure doesn't support other search methods

### Binary Search Algorithm

Binary search is like the strategy you use when guessing a number between 1-100 and being told "higher" or "lower" after each guess. It only works on **sorted** data, but it's much faster for large datasets!

```
Binary Search for value 31:
Sorted Array: [2, 5, 8, 12, 16, 23, 31, 42, 50, 67, 88, 90]

Step 1: Calculate mid = (0 + 11) / 2 = 5
   [2, 5, 8, 12, 16, 23, 31, 42, 50, 67, 88, 90]
                    ^
   23 < 31, so search right half
   left = mid + 1 = 6, right = 11

Step 2: Calculate mid = (6 + 11) / 2 = 8
   [2, 5, 8, 12, 16, 23, 31, 42, 50, 67, 88, 90]
                                ^
   50 > 31, so search left half
   left = 6, right = mid - 1 = 7

Step 3: Calculate mid = (6 + 7) / 2 = 6
   [2, 5, 8, 12, 16, 23, 31, 42, 50, 67, 88, 90]
                         ^
   31 == 31, found at index 6!
```

```cpp
int binary_search(const int arr[], int size, int value) {
    int left = 0;                // Start of search range
    int right = size - 1;        // End of search range
    
    while (left <= right) {      // While there are elements to check
        // Find the middle element (written this way to avoid integer overflow)
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == value) {
            return mid;          // We found it!
        } else if (arr[mid] < value) {
            left = mid + 1;      // Value must be in the right half
        } else {
            right = mid - 1;     // Value must be in the left half
        }
    }
    
    return -1;                   // Value not found in the array
}
```

**How It Works:**
1. Define your search range (initially the whole array)
2. Find the middle element of your current search range
3. Compare the middle element to your target value:
   - If they match, you're done!
   - If the middle element is smaller than your target, look in the right half
   - If the middle element is larger than your target, look in the left half
4. Repeat steps 2-3 with your new, smaller search range
5. If your search range becomes empty, the value isn't in the array

**Time Complexity Analysis**:
- **Best case**: O(1) - Element found at the middle on the first try
- **Average and worst case**: O(log n) - The search space is divided in half with each step
- **Space complexity**: O(1) iterative version, O(log n) for recursive version (due to function call stack)

**Why is it O(log n)?**
After each comparison, the search space gets divided by 2:
n → n/2 → n/4 → ... → 1

The number of steps k needed to reach 1 is:
n / 2^k = 1
Solving for k: k = log₂(n)

Think of it this way: if you have 1,000,000 elements, you can find any element in at most 20 steps!

```
Visual representation of binary search reducing the search space:

Initial array with 16 elements (n = 16):
[ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15]
                        ^
                  Check middle (7)

If target > middle, search right half (n/2 = 8):
                        [ 8 | 9 | 10| 11| 12| 13| 14| 15]
                                  ^
                            Check middle (11)

If target < middle, search left half (n/4 = 4):
                        [ 8 | 9 | 10| 11]
                            ^
                      Check middle (9)

If target > middle, search right half (n/8 = 2):
                              [10| 11]
                               ^
                         Check middle (10)

With n = 16, we needed at most log₂(16) = 4 steps
With n = 1,000,000, we need at most log₂(1,000,000) ≈ 20 steps
```

**When to use binary search:**
- When your data is sorted
- When you have a large dataset
- When you need very fast search times
- When the cost of sorting can be amortized over many searches

### Efficient Counting in Sorted Arrays

Sometimes we need to count how many times a value appears in an array. For unsorted arrays, we need to check every element (O(n)). But for sorted arrays, we can use binary search to find the boundaries of where the value appears!

```
Counting occurrences of value 5 in a sorted array:
Array: [1, 2, 3, 5, 5, 5, 5, 7, 8, 9]

First, find the leftmost occurrence:
1. Start with full array, mid = 4
   [1, 2, 3, 5, 5, 5, 5, 7, 8, 9]
               ^
   5 == 5, but keep looking left
   
2. Search left half, mid = 1
   [1, 2, 3, 5, 5]
       ^
   2 < 5, look in right half
   
3. Search right half, mid = 3
   [3, 5, 5]
        ^
   5 == 5, but keep looking left
   
4. Search left half, mid = 2
   [3, 5]
        ^
   5 == 5, first is at index 3

Then, find the rightmost occurrence:
1. Start with full array, mid = 4
   [1, 2, 3, 5, 5, 5, 5, 7, 8, 9]
               ^
   5 == 5, but keep looking right
   
2. Search right half, mid = 7
   [5, 5, 5, 7, 8, 9]
           ^
   7 > 5, look in left half
   
3. Search left half, mid = 5
   [5, 5, 5]
        ^
   5 == 5, but keep looking right
   
4. Search right half, no more elements
   Last is at index 6

Count = (last index - first index + 1) = (6 - 3 + 1) = 4
```

```cpp
int count_occurrences_efficient(const int sorted_arr[], int size, int value) {
    // Step 1: Find the first occurrence using binary search
    int first = -1;
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sorted_arr[mid] == value) {
            first = mid;              // Remember this position
            right = mid - 1;          // Keep looking left for earlier occurrences
        } else if (sorted_arr[mid] < value) {
            left = mid + 1;           // Look in right half
        } else {
            right = mid - 1;          // Look in left half
        }
    }
    
    if (first == -1) return 0;        // Value not found at all
    
    // Step 2: Find the last occurrence using binary search
    int last = -1;
    left = 0;
    right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sorted_arr[mid] == value) {
            last = mid;               // Remember this position
            left = mid + 1;           // Keep looking right for later occurrences
        } else if (sorted_arr[mid] < value) {
            left = mid + 1;           // Look in right half
        } else {
            right = mid - 1;          // Look in left half
        }
    }
    
    // Count = last index - first index + 1
    return last - first + 1;
}
```

**How It Works:**
1. We do two binary searches:
   - First to find the leftmost occurrence of the value
   - Second to find the rightmost occurrence of the value
2. The total count is (last position - first position + 1)

**Time Complexity**: O(log n) for finding both boundaries, compared to O(n) for checking every element linearly.

### Algorithm Performance Measurement

Comparing algorithm performance involves:

1. **Theoretical analysis**: Using Big O notation to predict how an algorithm's running time grows as the input gets larger
2. **Empirical measurement**: Actually timing how long the algorithm takes with different input sizes

The difference between O(n) and O(log n) becomes dramatic as input size increases:

| Input size (n) | O(n) operations | O(log n) operations |
|----------------|-----------------|---------------------|
| 10             | 10              | 3-4                 |
| 100            | 100             | 6-7                 |
| 1,000          | 1,000           | 9-10                |
| 1,000,000      | 1,000,000       | 19-20               |

For example, on a computer that can do 1 billion operations per second:
- A linear search through 1 billion items might take 1 second
- A binary search through 1 billion items might take only 30 operations (nanoseconds)!

### Cache Considerations for Real-World Performance

Modern computers don't access all memory equally quickly. They use a system of memory caches:

1. **L1 cache**: Tiny but extremely fast memory (a few KB, ~1 nanosecond access)
2. **L2 cache**: Larger but a bit slower (a few hundred KB, ~3-10 ns)
3. **L3 cache**: Even larger but slower still (a few MB, ~10-20 ns)
4. **Main memory (RAM)**: Much larger but much slower (GB, ~100 ns)

This creates interesting real-world effects:
- **Linear search** has better **spatial locality** (accessing memory locations that are next to each other), which is cache-friendly
- **Binary search** jumps around in memory, which can cause more cache misses

```
Memory access patterns visualization:

Linear Search:
Memory: [0][1][2][3][4][5][6][7][8][9]...
Access: [0]→[1]→[2]→[3]→...
        Sequential access pattern is cache-friendly!

Binary Search:
Memory: [0][1][2][3][4][5][6][7][8][9][10][11][12][13][14][15]...
Access: [7]→[3]→[1]→[0]
        Or:  [7]→[11]→[13]→[14]
        Jumping pattern can cause cache misses!

Cache behavior:
┌────────────────────┐
│ CPU                │
├────────────────────┤
│ L1 Cache (fastest) │ ← Linear search might keep all needed 
├────────────────────┤   data in cache after first access
│ L2 Cache           │
├────────────────────┤
│ L3 Cache           │
├────────────────────┤
│ RAM (slowest)      │ ← Binary search might need to access
└────────────────────┘   RAM multiple times due to jumps
```

This is why, for small arrays (typically less than ~100 elements), linear search can sometimes be faster than binary search in practice, despite having worse theoretical complexity!

### Key Takeaways

1. **Linear search** works on any array but is slow for large datasets (O(n))
2. **Binary search** only works on sorted arrays but is much faster (O(log n))
3. Always consider whether your data is sorted when choosing a search algorithm
4. For extremely large datasets, the efficiency of binary search becomes critical
5. Remember that theoretical analysis (Big O) doesn't tell the whole story for small inputs
