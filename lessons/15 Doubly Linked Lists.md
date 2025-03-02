## Lesson 15: Doubly Linked List

This lesson extends linked lists with bidirectional traversal capabilities:

### Bidirectional Node Structure

Doubly linked list nodes contain both next and previous pointers:

```
Memory layout of a doubly linked list:

         +-----------------+     +-----------------+     +-----------------+
nullptr<-|Prev|Data|Next|--+---->|Prev|Data|Next|--+---->|Prev|Data|Next|--->nullptr
         +-----------------+     +-----------------+     +-----------------+
            ^                       ^                       ^
            |                       |                       |
           head                                           tail
```

This lets us traverse in both directions and efficiently access the last element via the `tail` pointer.

### Memory Management Complexity

Managing bidirectional links requires careful pointer manipulation:

```cpp
void push_front(const T &value) {
    Node *new_node = new Node(value);
    
    if (head == nullptr) {
        // Empty list case
        head = tail = new_node;
    } else {
        // Non-empty list
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    
    size++;
}
```

Every insertion or deletion must maintain both forward and backward links, making operations more complex than in singly linked lists.

### Tail Pointer Optimization

The `tail` pointer enables O(1) operations at both ends:

```cpp
void push_back(const T &value) {
    Node *new_node = new Node(value);
    
    if (tail == nullptr) {
        // Empty list case
        head = tail = new_node;
    } else {
        // Non-empty list
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    
    size++;
}
```

This avoids the O(n) traversal that would be needed in a singly linked list.

### Bidirectional Traversal

Bidirectional traversal enables operations like printing backward:

```cpp
void print_backward() const {
    Node *current = tail;
    
    while (current != nullptr) {
        // Process current->data
        current = current->prev;
    }
}
```

This is useful for applications requiring reverse iteration like text editors, undo systems, or browsing history.

### Insertion Before a Given Element

Doubly linked lists simplify insertion before a known element:

```cpp
bool insert_before(const T &search_value, const T &new_value) {
    // Find node with search_value
    Node *current = head;
    while (current != nullptr) {
        if (current->data == search_value) {
            // Found the node, insert before it
            
            if (current == head) {
                // Special case: inserting before head
                push_front(new_value);
            } else {
                // General case: insert between nodes
                Node *new_node = new Node(new_value);
                new_node->next = current;
                new_node->prev = current->prev;
                current->prev->next = new_node;
                current->prev = new_node;
                size++;
            }
            
            return true;
        }
        current = current->next;
    }
    
    return false;  // Value not found
}
```

This would be much more complex in a singly linked list, requiring either a separate tracking pointer or a two-pass approach.

### List Reversal Algorithm

The `reverse` method demonstrates complex pointer manipulation:

```cpp
void reverse() {
    if (head == nullptr || head == tail) {
        return;  // Empty or single-element list
    }
    
    Node *current = head;
    Node *temp = nullptr;
    
    // Swap head and tail
    tail = head;
    
    while (current != nullptr) {
        // Save next node
        temp = current->next;
        
        // Swap next and prev pointers
        current->next = current->prev;
        current->prev = temp;
        
        // Move to the next node (which is now prev)
        current = temp;
    }
    
    // Update head to the last node
    head = tail->prev;
}
```

This in-place algorithm swaps all next and prev pointers, effectively reversing the traversal direction.

### Memory Overhead Analysis

Doubly linked lists have greater memory overhead than singly linked lists:
- Each node requires two pointers instead of one
- For a typical system with 64-bit pointers, each node has 16 bytes of pointer overhead
- A doubly linked list of integers might use 20-24 bytes per element (4 bytes for data, 16 for pointers, plus alignment)

This is a classic space-time tradeoff, using more memory to enable more efficient operations.
