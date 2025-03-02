## Lesson 14: Singly Linked List

This lesson explores a fundamental sequential data structure with non-contiguous memory allocation:

### Node-Based Structure

A singly linked list consists of nodes, each containing data and a pointer to the next node:

```
Memory layout of a linked list:

Node 1       Node 2       Node 3
+------+     +------+     +------+
| Data |     | Data |     | Data |
+------+     +------+     +------+
| Next |---->| Next |---->| Next |---->nullptr
+------+     +------+     +------+
```

The `head` pointer lets us access the first node, and traversal follows the `next` pointers.

### Memory Allocation Pattern

Each node is allocated individually on the heap:

```cpp
void push_front(const T &value) {
    Node *new_node = new Node(value);  // Allocate new node
    new_node->next = head;             // Link to current head
    head = new_node;                   // Update head pointer
    size++;
}
```

This pattern:
- Allocates memory for a single node at a time
- Never needs to relocate existing nodes (unlike vectors)
- May result in poor cache locality if nodes are scattered in memory
- Requires manual memory management for each node

### Traversal Algorithm

Finding an element requires sequential traversal:

```cpp
bool find(const T &value) const {
    Node *current = head;
    
    while (current != nullptr) {
        if (current->data == value) {
            return true;  // Found
        }
        current = current->next;  // Move to next node
    }
    
    return false;  // Not found
}
```

This is an O(n) operation because, in the worst case, we need to check every node.

### Insertion and Deletion

Insertion and deletion are efficient when the position is known:

**Insertion at beginning (push_front)**:
```cpp
void push_front(const T &value) {
    Node *new_node = new Node(value);
    new_node->next = head;
    head = new_node;
    size++;
}
```
Time complexity: O(1)

**Insertion at end (push_back)**:
```cpp
void push_back(const T &value) {
    Node *new_node = new Node(value);
    
    if (head == nullptr) {
        head = new_node;
    } else {
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
    
    size++;
}
```
Time complexity: O(n) because we need to find the end

**Deletion from beginning (pop_front)**:
```cpp
void pop_front() {
    if (head == nullptr) {
        throw std::out_of_range("List is empty");
    }
    
    Node *temp = head;
    head = head->next;
    delete temp;
    size--;
}
```
Time complexity: O(1)

### Resource Management

The destructor must clean up all allocated nodes:

```cpp
~SinglyLinkedList() {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;  // Save next pointer
        delete current;              // Free current node
        current = next;              // Move to saved next node
    }
}
```

This prevents memory leaks by systematically freeing each node.

### Deep Copy Implementation

Copy operations must duplicate the entire list structure:

```cpp
SinglyLinkedList(const SinglyLinkedList &other) : head(nullptr), size(0) {
    // Copy each node from other list
    for (Node *current = other.head; current != nullptr; current = current->next) {
        push_back(current->data);
    }
}
```

This ensures that modifying one list doesn't affect its copies.

### Memory Usage Analysis

Compared to arrays/vectors, linked lists:
- Use more memory per element (data + pointer vs. just data)
- Have higher memory overhead (typically 8 bytes per element for a next pointer)
- Allow more flexible memory usage (can utilize fragmented memory)
- Don't waste memory for unused capacity

A singly linked list of integers might use 12-16 bytes per element (4 bytes for the integer, 8 bytes for the pointer, plus potential alignment padding).
