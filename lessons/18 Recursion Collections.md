## Lesson 18: Recursion with Collections

This lesson applies recursion to process collections of data:

### Recursive Binary Search

Binary search is elegantly expressed recursively:

```cpp
int binary_search_recursive(const std::vector<int> &arr, int target, 
                            int left, int right) {
    // Base case: not found
    if (left > right) {
        return -1;
    }
    
    // Calculate middle point
    int mid = left + (right - left) / 2;
    
    // Check if target is at mid
    if (arr[mid] == target) {
        return mid;
    }
    
    // Recursively search appropriate half
    if (arr[mid] > target) {
        return binary_search_recursive(arr, target, left, mid - 1);
    } else {
        return binary_search_recursive(arr, target, mid + 1, right);
    }
}
```

This follows the divide-and-conquer paradigm:
1. Divide the problem (search space) in half
2. Conquer by recursively searching the appropriate half
3. Combine the results (simply return the found index or -1)

The time complexity is O(log n), but the space complexity is also O(log n) due to the recursion stack.

### Recursive Array Sum

Summing an array demonstrates the principle of breaking down collection processing:

```cpp
int sum_array(const std::vector<int> &arr, int index) {
    // Base case: reached the end
    if (index >= arr.size()) {
        return 0;
    }
    
    // Recursive case: current element + sum of rest
    return arr[index] + sum_array(arr, index + 1);
}
```

This follows a pattern of:
1. Process the current element
2. Recursively process the rest of the collection
3. Combine the results

### Recursive Maximum Finding

Finding the maximum value shows how to accumulate results:

```cpp
int find_max(const std::vector<int> &arr, int index) {
    // Base case: single element
    if (index == arr.size() - 1) {
        return arr[index];
    }
    
    // Find maximum of rest of array
    int max_rest = find_max(arr, index + 1);
    
    // Return larger of current element and maximum of rest
    return std::max(arr[index], max_rest);
}
```

This recursively:
1. Finds the maximum of the subarray starting from index+1
2. Compares it with the current element
3. Returns the larger value

### Memoization Technique

Memoization dramatically improves performance for recursive functions with overlapping subproblems:

```cpp
int fibonacci_memo(int n, std::unordered_map<int, int> &memo) {
    // Check if already computed
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    
    // Base cases
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    // Compute and store result
    memo[n] = fibonacci_memo(n - 1, memo) + fibonacci_memo(n - 2, memo);
    return memo[n];
}
```

Without memoization, the naive recursive Fibonacci has exponential O(2^n) time complexity. With memoization, it becomes linear O(n) time and space.

This technique:
- Caches results of function calls to avoid redundant computation
- Trades memory for speed
- Is a form of dynamic programming
- Works best when there are many repeated subproblems

### Recursive vs. Bottom-Up Approach

The same problems can often be solved with either recursive (top-down) or iterative (bottom-up) approaches:

**Top-down with memoization (recursive)**:
```cpp
int fibonacci_memo(int n, std::unordered_map<int, int> &memo) {
    if (memo.find(n) != memo.end()) return memo[n];
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    memo[n] = fibonacci_memo(n - 1, memo) + fibonacci_memo(n - 2, memo);
    return memo[n];
}
```

**Bottom-up (iterative)**:
```cpp
int fibonacci_bottom_up(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    std::vector<int> dp(n + 1, 0);
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[n];
}
```

The bottom-up approach:
- Avoids recursion overhead
- Has deterministic memory usage
- Often more efficient but may be less intuitive
- Builds solutions to smaller subproblems first, then combines them
