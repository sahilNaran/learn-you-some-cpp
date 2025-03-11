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

#### Map Operations
- **insert()**: O(log n) - need to find position and rebalance
- **find()**: O(log n) - binary search through the tree
- **erase()**: O(log n) - delete and rebalance
- **Iteration**: O(n) - in-order traversal visits all nodes
- **lower_bound()/upper_bound()**: O(log n) - find position based on key comparison

#### Performance Characteristics
- All operations guaranteed O(log n) in worst case
- Self-balancing ensures performance even with sorted insertions
- More memory overhead compared to unordered_map
- Key comparison must be defined (requires < operator)

The tree is kept balanced to ensure log(n) operations even in worst cases. The specific balancing mechanism (red-black tree) is covered in the Further Reading section below.

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
                                    const std::vector<int> &nums2) {
                                        std::vector<int> find_intersection(const std::vector<int> &nums1, 
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

### Tree Data Structures - A Progression

To fully understand the implementation of STL containers like `std::map` and `std::set`, we need to explore the evolution of tree data structures that led to red-black trees. This section provides a comprehensive explanation of each tree type in the progression.

#### 1. General Trees

Trees are hierarchical data structures that represent relationships with a parent-child structure. Unlike linear data structures (arrays, linked lists), trees enable hierarchical organization of data.

```
       A         → Root node
     / | \
    B  C  D      → Internal nodes (have both parent and children)
   / \    |
  E   F   G      → Leaf nodes (have no children)
```

**Terminology and Properties**:
- **Node**: Each element in a tree (contains data and links to children)
- **Edge**: Connection between two nodes
- **Root**: Topmost node with no parent (node A in the example)
- **Parent/Child**: Relationship between connected nodes (A is parent to B, C, D)
- **Siblings**: Nodes sharing the same parent (B, C, D are siblings)
- **Leaf**: Node with no children (E, F, G in example)
- **Internal Node**: Non-leaf node with at least one child
- **Depth**: Distance from root (A has depth 0, B has depth 1, E has depth 2)
- **Height**: Length of longest path to leaf (tree height is 2 in example)
- **Degree**: Number of children a node has (A has degree 3)
- **Subtree**: Tree formed by a node and its descendants

**Traversal Methods**:
- **Pre-order**: Visit node, then left subtree, then right subtree (A,B,E,F,C,D,G)
- **Post-order**: Visit left subtree, then right subtree, then node (E,F,B,C,G,D,A)
- **Level-order**: Visit by levels, from top to bottom (A,B,C,D,E,F,G)

**Real-world Applications**:
- File systems (directories and files)
- Organization charts
- DOM (Document Object Model) in web browsers
- Family trees and hierarchical taxonomies

**Advantages**:
- Represents hierarchical relationships naturally
- Enables efficient insertion/deletion in some variants
- Provides framework for more specialized tree types

**Limitations**:
- Basic trees don't guarantee balance or performance
- Without structure, operations can be O(n) in worst case

#### 2. Binary Trees

Binary trees are a specialization where each node has at most two children, typically referred to as "left" and "right" children.

```
      A
     / \
    B   C    ← B is left child of A, C is right child
   / \   \
  D   E   F
 /
G
```

**Types of Binary Trees**:
- **Full Binary Tree**: Every node has 0 or 2 children (no nodes with only one child)
- **Complete Binary Tree**: All levels filled except possibly the last, which is filled from left
- **Perfect Binary Tree**: All internal nodes have exactly 2 children and all leaf nodes are at the same level
- **Balanced Binary Tree**: Height is O(log n), enabling efficient operations

**Node Structure (in C++)**:
```cpp
template <typename T>
struct BinaryTreeNode {
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    
    BinaryTreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};
```

**Traversal Methods (with example from diagram)**:
- **In-order**: Left → Node → Right (G,D,B,E,A,C,F) - gives sorted order in BSTs
- **Pre-order**: Node → Left → Right (A,B,D,G,E,C,F) - useful for copying trees
- **Post-order**: Left → Right → Node (G,D,E,B,F,C,A) - useful for deletion
- **Level-order**: Level by level from root (A,B,C,D,E,F,G) - breadth-first approach

**Properties**:
- Height ranges from log₂(n+1) (perfect) to n (degenerate)
- A tree with n nodes has exactly n-1 edges
- Maximum nodes at level i is 2ⁱ (zero-indexed levels)
- Maximum nodes in tree of height h is 2^(h+1) - 1

**Applications**:
- Expression trees for mathematical expressions
- Huffman coding trees for compression
- Binary heaps for priority queues
- Foundation for more specialized trees (BST, AVL, etc.)

**Implementation Considerations**:
- Can be implemented using linked structures or arrays
- Array implementation: For node at index i, left child at 2i+1, right at 2i+2
- Linked implementation more flexible but uses more memory for pointers

#### 3. Binary Search Trees (BSTs)

Binary Search Trees add an ordering property to binary trees, enabling efficient search, insertion, and deletion.

```
      8         ← Root
     / \
    3   10      ← Internal nodes
   / \    \
  1   6    14   ← Internal/leaf nodes
     / \   /
    4   7 13    ← Leaf nodes
```

**Ordering Property**:
- For every node N:
  - All nodes in N's left subtree have values < N's value
  - All nodes in N's right subtree have values > N's value
- This creates an in-order traversal that visits nodes in sorted order

**Detailed Operations**:

1. **Search** - O(log n) average, O(n) worst case:
   ```
   To find value 6 in example tree:
   1. Start at root (8): 6 < 8, go left
   2. Check node 3: 6 > 3, go right
   3. Found 6, return
   ```

2. **Insertion** - O(log n) average, O(n) worst case:
   ```
   To insert value 5:
   1. Start at root (8): 5 < 8, go left
   2. Check node 3: 5 > 3, go right
   3. Check node 6: 5 < 6, go left
   4. Node 4: 5 > 4, go right
   5. Empty position, insert 5 as right child of 4
   ```

3. **Deletion** - O(log n) average, O(n) worst case:
   - Case 1: Leaf node (just remove it)
   - Case 2: Node with one child (replace with its child)
   - Case 3: Node with two children (replace with in-order successor or predecessor)

**Example of Degenerate BST (worst case)**:
```
1
 \
  2
   \
    3     ← Effectively a linked list
     \
      4    Operations become O(n)
```

**Causes of Degeneration**:
- Inserting already sorted data
- Random deletions creating imbalance
- No rebalancing mechanism

**Performance Analysis**:
- Average case (randomly built): O(log n) for search, insert, delete
- Worst case (degenerate): O(n) for all operations
- Space complexity: O(n) for n nodes

**Limitations Addressed by Balanced Trees**:
- BSTs have no mechanism to maintain balance
- Performance degrades with unfortunate insertion/deletion patterns
- Need self-balancing mechanism → AVL, Red-Black Trees

**Implementation Notes**:
```cpp
// Simple BST insertion in C++
void insert(Node* &root, int value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }
    
    if (value < root->data)
        insert(root->left, value);
    else
        insert(root->right, value);
}
```

#### 4. AVL Trees

AVL trees (named after inventors Adelson-Velsky and Landis) are self-balancing BSTs that maintain height balance through rotations.

```
    Balance factors shown in parentheses:
        7(0)
       /    \
    3(-1)    10(0)
    / \        \
 1(0)  5(0)    15(0)
```

**Definition of Balance**:
- For every node, height of left and right subtrees differs by at most 1
- **Balance Factor** = height(right subtree) - height(left subtree)
- Valid balance factors are -1, 0, and 1
- Balance factor stored in each node or calculated when needed

**Height Properties**:
- Minimum height: log₂(n)
- Maximum height: 1.44 × log₂(n)
- AVL trees are more strictly balanced than red-black trees

**Detailed Rotations**:

1. **Left Rotation** (for right-heavy imbalance):
   ```
   Before:       After:
       A(2)         B(0)
      / \          / \
     X  B(1)  →   A(0) Z(0)
       / \        / \
      Y   Z      X   Y
   ```
   
2. **Right Rotation** (for left-heavy imbalance):
   ```
   Before:       After:
       A(-2)        B(0)
      / \          / \
     B(-1) Z  →   X(0) A(0)
    / \              / \
   X   Y            Y   Z
   ```

3. **Left-Right Rotation** (double rotation):
   ```
   Before:          After:
       A(-2)          Y(0)
      / \            / \
     B(1)  Z  →     B(0) A(0)
    / \            /     \
   X   Y          X       Z
   ```
   
4. **Right-Left Rotation** (double rotation):
   ```
   Before:          After:
       A(2)           Y(0)
      / \            / \
     X  B(-1)  →    A(0) B(0)
       / \          /     \
      Y   Z        X       Z
   ```

**Insertion Process**:
1. Insert like a normal BST
2. Update balance factors on the path back to root
3. If any node becomes unbalanced (balance factor ±2):
   - Determine the case (left-heavy or right-heavy)
   - Apply appropriate rotation(s)
   - Continue up to root

**Deletion Process**:
1. Delete like normal BST
2. Update balance factors on the path to root
3. Rebalance any unbalanced nodes with rotations
4. May require multiple rotations up the tree

**Time Complexity Analysis**:
- Search: O(log n) - guaranteed by balanced height
- Insert: O(log n) - BST insertion + up to one rotation
- Delete: O(log n) - BST deletion + up to log(n) rotations
- Space: O(n) for n nodes

**Advantages**:
- Guaranteed O(log n) operations
- Perfect height balance (stricter than red-black)
- Self-adjusting after modifications

**Disadvantages**:
- Requires more rotations than red-black trees
- Needs to store balance factors
- More complex insertion/deletion

#### 5. 2-3 Trees

2-3 trees are balanced search trees where nodes can have either 1 or 2 values and 2 or 3 children, providing a bridge to understand B-trees and red-black trees.

```
    [10,20]           ← 3-node with 2 keys and 3 children
   /   |   \
 [5]  [15] [30,40]    ← 2-node with 1 key, 3-node with 2 keys
```

**Node Types**:
- **2-node**: Contains 1 value and has 2 children (like BST node)
- **3-node**: Contains 2 values and has 3 children
- Values within a node are ordered (smaller value on left)

**Ordering Property**:
- For a 2-node with value X:
  - Left subtree contains values < X
  - Right subtree contains values > X
- For a 3-node with values X and Y (X < Y):
  - Left subtree contains values < X
  - Middle subtree contains values between X and Y
  - Right subtree contains values > Y

**Perfect Balance Property**:
- All leaf nodes are at the same level
- Every path from root to leaf has same length
- Height is logarithmic in number of elements

**Detailed Insertion Process**:
1. Find appropriate leaf for insertion
2. Add key to leaf node
3. If node overflows (becomes a 4-node with 3 values):
   - Split into two 2-nodes
   - Send middle value up to parent
   - If parent overflows, repeat procedure up the tree
   - May create new root (increasing height)

**Insertion Example**:
```
Insert 25 into:
    [10,20]
   /   |   \
 [5]  [15] [30,40]

Step 1: 25 belongs between 20 and 30
Step 2: Create temporary 4-node [30,35,40]
Step 3: Split into [30] and [40], push 35 up
Result:
      [10,20,35]
     /    |    \
   [5]   [15]  [30]  [40]
```

**Deletion Process**:
1. For leaf node: Remove if it's a 3-node; if 2-node, borrow or merge
2. For internal node: Replace with successor, then handle leaf deletion
3. May require redistribution (borrowing) or fusion (merging) of nodes

**Connection to Red-Black Trees**:
- Every 2-3 tree can be represented as a red-black tree
- 2-node ↔ black node
- 3-node ↔ black node with red child
- This connection explains red-black tree properties

**Performance**:
- Height between log₃(n) and log₂(n)
- All operations O(log n) worst case
- More complex but fewer rotations than AVL

**Advantages**:
- Perfect height balance
- Fewer restructuring operations than AVL trees
- Direct mapping to B-trees and red-black trees

#### 6. Red-Black Trees

Red-black trees are self-balancing binary search trees used in the implementation of `std::map` and `std::set` in the STL. They provide an efficient binary representation of 2-3 trees.

```
                [7,B]
               /     \
        [3,R]         [10,B]
        /    \            \
   [1,B]     [5,B]       [15,R]
```
B = Black node, R = Red node

**Core Properties**:
1. **Every node is colored either red or black**:
   - Typically implemented as a single bit in each node
   - Coloring encodes the structure of an equivalent 2-3 tree

2. **The root is always black**:
   - Ensures consistent handling of root cases
   - Simplifies insertion and deletion algorithms

3. **All NULL leaves (NIL) are considered black**:
   - These aren't usually actual nodes but conceptual null pointers
   - Ensures every path has consistent black height

4. **If a node is red, both its children must be black** (No red-red violations):
   - Prevents consecutive red nodes in any path
   - Ensures no path is more than twice as long as another

5. **Every path from root to leaves contains the same number of black nodes** (Black height property):
   - Critical for ensuring balanced tree height
   - If black height is h, tree height is at most 2h

**Node Structure**:
```cpp
template <typename Key, typename Value>
struct RBNode {
    Key key;
    Value value;
    RBNode* left;
    RBNode* right;
    RBNode* parent;
    enum Color { RED, BLACK } color;
    
    RBNode(Key k, Value v) 
        : key(k), value(v), left(nullptr), right(nullptr), 
          parent(nullptr), color(RED) {}
};
```

**Detailed Insertion Algorithm**:
1. Insert like a normal BST, color the new node RED
2. Fix any red-red violations by:
   - Case 1: If uncle is red → Recolor parent, uncle, and grandparent
   - Case 2: If uncle is black (triangle) → Single rotation
   - Case 3: If uncle is black (line) → Double rotation
3. Ensure root remains black

**Insertion Example**:
```
Initial tree:        After inserting 4 (red):    After fixing (recolor):
    10B                    10B                      10B
   /   \                  /   \                    /   \
  5B    15B              5B    15B                5R    15B
 /                      /                        /
2R                     2R                       2B
                         \                        \
                          4R (red-red!)            4R
```

**Detailed Deletion Algorithm**:
1. Standard BST deletion
2. If deleted node is BLACK, tree might become unbalanced
3. Six different cases to restore black height property:
   - Cases involve rotations and recoloring
   - More complex than insertion cases
4. Ensure root remains black

**Visualizing Red-Black Trees as 2-3 Trees**:
- Black node with red left child = 3-node (left small)
- Black node with red right child = 3-node (right small)
- Black node with no red children = 2-node

**Performance Analysis**:
- Height: At most 2×log₂(n+1) for n nodes
- Search: O(log n) - follows BST properties
- Insert: O(log n) - BST insertion + at most 2 rotations
- Delete: O(log n) - BST deletion + at most 3 rotations
- Space: O(n) for n nodes + 1 bit per node for color

**Advantages over AVL Trees**:
- Fewer rotations during insertion and deletion
- Better performance for frequent modifications
- Still maintains O(log n) height bound
- More memory efficient (only 1 color bit vs. balance factor)

#### What Makes Red-Black Trees Ideal for STL:
1. **Efficient Operations**: Guaranteed O(log n) performance for search, insert, delete
2. **Memory Overhead**: Only 1 bit per node needed for color (vs. full balance factor)
3. **Insertion/Deletion Efficiency**: Fewer rotations than AVL trees (max 2 for insert)
4. **Well-Studied Algorithms**: Mature implementation techniques with decades of optimization
5. **In-Order Traversal**: Naturally provides sorted key iteration for maps/sets
6. **Balance Trade-off**: Accepts slightly less perfect balance for better modification performance

**STL Implementation Notes**:
- The C++ Standard doesn't mandate red-black trees, but most implementations use them
- GCC's libstdc++ and LLVM's libc++ both use red-black trees for map/set
- Microsoft's STL also uses red-black trees for these containers

#### 7. B-Trees

B-Trees extend 2-3 trees to handle large numbers of keys and children, optimized for systems where data must be fetched from disk or slow storage.

```
             [30,60]                     ← Root node with 2 keys
            /   |   \                    ← 3 child pointers
     [10,20]  [40,50]  [70,80,90]        ← Internal nodes
    /  |  \    / | \    /  |  \  \       ← Child pointers
   ... ... ...  ... ...  ... ... ... ... ← Leaf nodes (data or more pointers)
```

**Formal Definition**:
- Order-m B-tree (m ≥ 3):
  - Root has between 1 and m-1 keys
  - All other nodes have between ⌈m/2⌉-1 and m-1 keys
  - Non-leaf node with k keys has k+1 children
  - All leaves at same level (perfect height balance)

**Key Properties**:
- Generalization of 2-3 trees to n-way branching
- Minimizes disk I/O by storing many keys per node
- Node size typically matches disk block size (e.g., 4KB)
- Height is logarithmic in number of elements
- Remains balanced through splits and merges

**Operations**:
1. **Search**: Follow pointers based on key comparison within nodes
2. **Insert**: 
   - Find leaf node
   - Insert key in order
   - If node overflows, split and push median key up
   - May propagate to root, increasing height
3. **Delete**:
   - Remove key
   - If node underflows (< ⌈m/2⌉-1 keys), either:
     - Redistribute keys from sibling
     - Merge with sibling and pull down parent key

**Real-world Usage**:
- Database indexing (MySQL InnoDB, PostgreSQL)
- File systems (NTFS, ext4, HFS+)
- Key-value stores and NoSQL databases

**Performance Characteristics**:
- Height: O(log_m(n)) where m is order of tree
- Search, insert, delete: O(log_m(n))
- Space: O(n) but with high utilization per node

**Advantages for External Storage**:
- Minimizes number of disk accesses
- High fanout (branching factor) reduces height
- Good cache locality when node fits in memory/cache line
- Efficient for range queries (sequential access)

**Variant: B+ Tree**:
- Data stored only in leaf nodes
- Internal nodes only store keys for routing
- Leaf nodes linked together for efficient range queries
- Commonly used in databases and file systems
