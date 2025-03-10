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

#### Red-Black Tree Properties
A red-black tree maintains these invariants:
1. Every node is either red or black
2. The root is black
3. All leaf nodes (NIL) are black
4. If a node is red, both its children are black
5. Every path from root to leaf contains the same number of black nodes

These properties ensure the tree remains balanced, with no path more than twice as long as any other.

```
A red-black tree structure for std::map:
                [key4,value4,B]
               /              \
      [key2,value2,R]         [key6,value6,R]
      /           \           /            \
[key1,value1,B] [key3,value3,B] [key5,value5,B] [key7,value7,B]

B = Black node
R = Red node
```

#### Internal Node Structure
Each node in the tree contains:
```
+------------------+
| key              | (by which elements are ordered)
+------------------+
| mapped value     | (the data associated with the key)
+------------------+
| color            | (red or black)
+------------------+
| pointer to left  | (points to node with smaller key)
+------------------+
| pointer to right | (points to node with larger key)
+------------------+
| pointer to parent| (facilitates tree operations)
+------------------+
```

#### Map Operations in Detail
1. **insert(key, value)**: O(log n)
   - Traverse the tree to find the insertion point (similar to BST)
   - Insert the new node (colored red initially)
   - Rebalance the tree if needed to maintain red-black properties
   - This may involve color changes and rotations (left/right)

2. **find(key)**: O(log n)
   - Standard binary search tree traversal
   - Compare key with current node
   - Go left if key < node's key, right if key > node's key
   - Return iterator to node if found, otherwise map::end()

3. **erase(key)**: O(log n)
   - Find the node to delete
   - Remove it using BST deletion
   - Rebalance the tree if needed
   - Special cases handled to maintain red-black properties

4. **Traversal/Iteration**: O(n)
   - In-order traversal gives keys in sorted order
   - Uses stack-based traversal or parent pointers
   - Provides bidirectional iterators

5. **lower_bound(key)/upper_bound(key)**: O(log n)
   - Find first element not less than key/first element greater than key
   - Uses tree traversal with path memory

#### Performance Characteristics
- All operations guaranteed O(log n) in worst case
- Self-balancing ensures performance even with sorted insertions
- Tree height is at most 2*log(n+1)
- More memory overhead compared to unordered_map
- Key comparison must be defined (requires < operator)

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

### Additional Container Types

#### List Implementation
The `std::list` is implemented as a doubly-linked list:
```
Doubly-linked list structure:
[prev|data|next] ⟺ [prev|data|next] ⟺ [prev|data|next]
```

Key operations:
- **insert() anywhere**: O(1) - with an iterator position
- **erase() anywhere**: O(1) - with an iterator position
- **push_back(), push_front()**: O(1)
- **find()**: O(n) - must traverse the list
- **Random access**: Not supported - must iterate to position

#### Deque Implementation
The `std::deque` (double-ended queue) provides efficient access at both ends:
```
Deque structure (typically implemented as a segmented array):
[control block] --> [block ptr array] --> [data block 0][data block 1]...
```

Key operations:
- **push_back(), push_front()**: Amortized O(1)
- **pop_back(), pop_front()**: O(1)
- **operator[]**: O(1) - but more complex than vector
- **insert()/erase() in middle**: O(n)

#### Priority Queue Implementation
The `std::priority_queue` is typically implemented as a binary heap:
```
Binary heap structure (array representation of complete binary tree):
      [0]
     /   \
   [1]   [2]
   / \   / \
 [3][4][5][6]...
```

Key operations:
- **push()**: O(log n) - insert and bubble up
- **pop()**: O(log n) - remove top and reheapify
- **top()**: O(1) - access maximum/minimum element

#### Set vs. Unordered Set
- `std::set`: Based on red-black tree, ordered elements, O(log n) operations
- `std::unordered_set`: Based on hash table, unordered, O(1) average operations

### Iterator Invalidation Rules

Understanding when iterators become invalid is crucial for correct code:

| Container | Operation | Iterators Invalidated |
|-----------|-----------|------------------------|
| vector    | insert/erase | All iterators from the point of modification to the end |
| vector    | reallocation (e.g., due to growth) | All iterators |
| list      | insert/erase | Only iterators pointing to the erased element |
| map/set   | insert | None |
| map/set   | erase | Only iterators pointing to the erased element |
| unordered_map | insert | All iterators if rehashing occurs, none otherwise |
| unordered_map | erase | Only iterators pointing to the erased element |

### Memory Allocation Strategies

#### Vector Growth
When a vector needs to grow:
1. Allocate new memory block (typically 1.5x or 2x the current capacity)
2. Copy/move all elements to the new location
3. Deallocate old memory
4. Update internal pointers

```
Vector growth example:
Initial: [e0][e1][e2][e3] (capacity = 4)
After growth: [e0][e1][e2][e3][__][__][__][__] (capacity = 8)
```

#### Memory Layout Comparison
- **Contiguous containers** (vector, deque):
  - Elements stored in adjacent memory
  - Better cache locality
  - Less memory overhead per element
  
- **Node-based containers** (list, map, set):
  - Elements stored in separate nodes across memory
  - Each node has overhead (pointers, etc.)
  - More stable memory addresses during modification

### Implementation Examples for Assignment Tasks

#### remove_duplicates Solution Approach
```cpp
std::vector<int> remove_duplicates(const std::vector<int> &nums) {
    std::unordered_set<int> seen;  // For O(1) lookup
    std::vector<int> result;
    
    for (int num : nums) {
        // If we haven't seen this number before
        if (seen.find(num) == seen.end()) {
            result.push_back(num);  // Add to result
            seen.insert(num);       // Mark as seen
        }
    }
    
    return result;
}
```

Key considerations:
- Using `unordered_set` for O(1) lookups outperforms `set` (O(log n))
- Preserves original order by iterating through input vector
- Could use `set` if ordering of unique elements is required

#### count_words Solution Approach
```cpp
std::map<std::string, int> count_words(const std::vector<std::string> &words) {
    std::map<std::string, int> word_counts;
    
    for (const auto &word : words) {
        word_counts[word]++;  // Increment count for each word
    }
    
    return word_counts;
}
```

Container choice considerations:
- `std::map`: Use when sorted output is required
- `std::unordered_map`: Use when performance is critical and order doesn't matter

### Custom Comparators and Hash Functions

#### Custom Comparator for Map/Set
```cpp
// Custom comparator for case-insensitive string comparison
struct CaseInsensitiveCompare {
    bool operator()(const std::string& a, const std::string& b) const {
        return std::lexicographical_compare(
            a.begin(), a.end(), b.begin(), b.end(),
            [](char a, char b) { return std::tolower(a) < std::tolower(b); }
        );
    }
};

// Usage
std::map<std::string, int, CaseInsensitiveCompare> case_insensitive_map;
```

#### Custom Hash Function for Unordered Containers
```cpp
// Custom hash function for a Point class
struct Point {
    int x, y;
    
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

struct PointHash {
    std::size_t operator()(const Point& p) const {
        // Combine hash of x and y
        return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
    }
};

// Usage
std::unordered_map<Point, std::string, PointHash> point_map;
```

### Container Adapter Classes

These classes provide a restricted interface to an underlying container:

#### Stack
```
+-------------+
| underlying  |    std::stack<T> wraps a container (default: std::deque)
| container   |    and provides LIFO (Last-In-First-Out) operations
+-------------+
```
- **push()**: Add element to top
- **pop()**: Remove element from top
- **top()**: Access top element
- All operations O(1) with default deque

#### Queue
```
+-------------+
| underlying  |    std::queue<T> wraps a container (default: std::deque)
| container   |    and provides FIFO (First-In-First-Out) operations
+-------------+
```
- **push()**: Add element to back
- **pop()**: Remove element from front
- **front()**: Access first element
- All operations O(1) with default deque

### Performance Comparison Table

| Operation               | vector   | list     | deque    | map      | unordered_map |
|-------------------------|----------|----------|----------|----------|---------------|
| Random Access           | O(1)     | O(n)     | O(1)     | O(log n) | O(1) avg      |
| Insert/Remove at Front  | O(n)     | O(1)     | O(1)     | -        | -             |
| Insert/Remove at Back   | O(1)*    | O(1)     | O(1)     | -        | -             |
| Insert in Middle        | O(n)     | O(1)**   | O(n)     | O(log n) | O(1) avg      |
| Find Element            | O(n)     | O(n)     | O(n)     | O(log n) | O(1) avg      |
| Memory Usage per Element| Low      | High     | Medium   | High     | High          |
| Iteration Performance   | Excellent| Good     | Good     | Good     | Fair          |
| Iterator Invalidation   | High     | Low      | Medium   | Low      | Medium        |

\* Amortized - may trigger reallocation  
\** With iterator position
