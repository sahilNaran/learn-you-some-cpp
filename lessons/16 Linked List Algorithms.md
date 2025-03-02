## Lesson 16: Linked List Algorithms

This lesson explores specialized algorithms for linked structures:

### Floyd's Cycle Detection Algorithm

This elegant algorithm detects cycles in linked lists:

```cpp
bool detect_cycle(Node *head) {
    if (head == nullptr) return false;
    
    Node *slow = head;  // Moves one step at a time
    Node *fast = head;  // Moves two steps at a time
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;  // Cycle detected
        }
    }
    
    return false;  // No cycle
}
```

**Mathematical insight**:
- If a cycle exists, the fast pointer will eventually "lap" the slow pointer
- When they meet, they're both inside the cycle
- The relative speeds ensure they will meet (not pass each other in between checks)

This uses O(1) extra space regardless of list size - a significant advantage over marking-based approaches.

### Finding the Middle Element

The runner technique efficiently finds the middle element:

```cpp
T find_middle(const SinglyLinkedList<T> &list) {
    Node *slow = list.head;
    Node *fast = list.head;
    
    // Fast pointer moves twice as fast as slow
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // When fast reaches the end, slow is at the middle
    return slow->data;
}
```

When the fast pointer reaches the end, the slow pointer will be at the middle:
- For odd-length lists: exactly at the middle
- For even-length lists: at the second middle element

This elegant technique avoids counting the list length first.

### Finding Cycle Start Point

We can extend Floyd's algorithm to find where a cycle begins:

```cpp
Node* find_cycle_start(Node *head) {
    if (head == nullptr) return nullptr;
    
    Node *slow = head;
    Node *fast = head;
    
    // First phase: detect cycle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            // Cycle detected, enter second phase
            slow = head;
            
            // Move both pointers at same speed
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            
            return slow;  // This is the start of the cycle
        }
    }
    
    return nullptr;  // No cycle
}
```

The mathematical insight here is fascinating:
- Let's say the distance from the head to the cycle start is 'a'
- And the distance from cycle start to the meeting point is 'b'
- The cycle length is 'c'
- When they meet, slow has traveled a+b steps and fast has traveled a+b+k*c steps (k is some integer)
- Since fast travels twice as fast, a+b+k*c = 2(a+b)
- Simplifying: a+b+k*c = 2a+2b
- Therefore: a = k*c-b
- This means if we put a pointer at the head and move it 'a' steps, it will reach the cycle start
- If we put another pointer at the meeting point and move it 'a' steps, it will go around the cycle k times and end up 'a' steps from the meeting point
- Since a = k*c-b, this point is also the cycle start

### Merge Two Sorted Lists

A common linked list algorithm merges two sorted lists:

```cpp
Node* merge_sorted_lists(Node* list1, Node* list2) {
    // Handle empty list cases
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;
    
    Node dummy(0);  // Dummy head node
    Node* tail = &dummy;
    
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    
    // Attach remaining nodes
    tail->next = (list1 != nullptr) ? list1 : list2;
    
    return dummy.next;
}
```

This algorithm:
- Uses a dummy head to simplify the code
- Merges in O(n+m) time where n and m are the list lengths
- Creates a new list that reuses the original nodes (no new memory allocation)
- Preserves the relative order of equal elements (stable merge)
