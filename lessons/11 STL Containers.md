## Lesson 11: STL Containers

This lesson explores the Standard Template Library's data structures and their implementations:

### Vector Implementation

The `std::vector` is a dynamic array that grows automatically:

```
Internal structure of std::vector:

+----------------+
| pointer to data | --> [element 0][element 1][element 2]...
+----------------+
| size           |
+----------------+
| capacity       |
+----------------+
```

Key operations and their complexities:
- **push_back()**: Amortized O(1) - may trigger resizing
- **operator[]**: O(1) - direct index access
- **insert() at arbitrary position**: O(n) - requires shifting elements
- **erase() at arbitrary position**: O(n) - requires shifting elements
- **size(), empty(), capacity()**: O(1) - simply return stored values

### Map Implementation

The `std::map` is typically implemented as a **red-black tree** (a self-balancing binary search tree):

```
A simplified red-black tree structure:
       [key3,value3]
      /            \
[key1,value1]   [key5,value5]
    /              /    \
[key0,value0] [key4,value4] [key6,value6]
```

This gives:
- **insert()**: O(log n) - need to find position and rebalance
- **find()**: O(log n) - binary search through the tree
- **erase()**: O(log n) - delete and rebalance
- **Iteration**: O(n) - in-order traversal visits all nodes

The tree is kept balanced to ensure log(n) operations even in worst cases.

### Unordered Map (Hash Map) Implementation

While not shown directly in the example, `std::unordered_map` uses hash tables:

```
Hash table structure:
Hash function: h(key) → bucket index

Buckets:
[0] → [key1,value1] → [key17,value17]  (collision chain)
[1] → [key8,value8]
[2] → empty
[3] → [key3,value3]
...
```

Operations:
- **insert(), find(), erase()**: O(1) average case, O(n) worst case
- **Hash function quality** is critical for performance
- **Load factor** (elements/buckets) affects performance - rehashing occurs when it exceeds a threshold
- **Collision resolution** typically uses chaining (linked lists of entries)

### Container Selection Strategy

The `most_frequent` function demonstrates container selection considerations:

```cpp
int most_frequent(const std::vector<int> &nums) {
    std::unordered_map<int, int> counts;
    
    // Build frequency map
    for (int num : nums) {
        counts[num]++;
    }
    
    // Find maximum frequency
    int max_count = 0;
    int result = 0;
    for (const auto &pair : counts) {
        if (pair.second > max_count) {
            max_count = pair.second;
            result = pair.first;
        }
    }
    
    return result;
}
```

This uses a hash map because:
- We need to associate values with their counts
- Fast lookups are critical for performance
- We don't need ordered traversal

### Set Operations with STL

The `find_intersection` function demonstrates using sets for mathematical operations:

```cpp
std::vector<int> find_intersection(const std::vector<int> &nums1, 
                                    const std::vector<int> &nums2) {
    std::set<int> set1(nums1.begin(), nums1.end());
    std::vector<int> result;
    
    for (int num : nums2) {
        if (set1.count(num) > 0) {
            result.push_back(num);
            set1.erase(num);  // Ensure each element appears only once
        }
    }
    
    return result;
}
```

This leverages:
- Sets for efficient membership testing - O(log n) lookup
- Sets to automatically remove duplicates from the first vector
- Erasure to handle duplicate elements in the second vector

For very large collections, specialized set intersection algorithms would be more efficient.
