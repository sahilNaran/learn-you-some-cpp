## Lesson 17: Recursion Basics

This lesson introduces the concept of recursion and how it's implemented:

### Recursion Mechanics and Call Stack

When a function calls itself, the system uses the call stack to manage each invocation:

```cpp
unsigned long long factorial_recursion(int n) {
    if (n <= 1) {
        return 1;  // Base case
    } else {
        return n * factorial_recursion(n - 1);  // Recursive case
    }
}
```

Execution of `factorial_recursion(4)`:

```
Stack frame 1: factorial_recursion(4)
  n = 4
  Calls factorial_recursion(3)
  
  Stack frame 2: factorial_recursion(3)
    n = 3
    Calls factorial_recursion(2)
    
    Stack frame 3: factorial_recursion(2)
      n = 2
      Calls factorial_recursion(1)
      
      Stack frame 4: factorial_recursion(1)
        n = 1
        Returns 1 (base case)
        
      Returns 2 * 1 = 2
      
    Returns 3 * 2 = 6
    
  Returns 4 * 6 = 24
```

Each recursive call:
1. Creates a new stack frame with its own local variables
2. Suspends the current execution
3. Proceeds with the recursive call
4. Resumes after the recursive call returns

### Base Cases and Termination

A critical component of recursion is the base case that stops recursion:

```cpp
int fibonacci(int n) {
    if (n <= 0) {
        return 0;  // Base case 1
    } else if (n == 1) {
        return 1;  // Base case 2
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive case
    }
}
```

Without a proper base case, recursion would continue indefinitely, causing a **stack overflow** when the call stack exceeds its memory limit.

### Call Stack Size Limits

Most systems have limited call stack size:
- Typically 1-8 MB on desktop systems
- Much smaller on embedded systems
- Each recursive call consumes stack space for:
  - Return address
  - Function parameters
  - Local variables
  - Register values

This limits the maximum recursion depth (often a few thousand calls on desktop systems).

### Tail Recursion

A special form of recursion where the recursive call is the final operation:

```cpp
// Not tail-recursive
int factorial_recursion(int n) {
    if (n <= 1) return 1;
    return n * factorial_recursion(n - 1);  // Must multiply after recursion
}

// Tail-recursive version
int factorial_tail(int n, int acc = 1) {
    if (n <= 1) return acc;
    return factorial_tail(n - 1, n * acc);  // Final operation is the recursive call
}
```

Tail recursion can be optimized by compilers through **tail call elimination**, which transforms recursion into iteration, avoiding stack overflow. However, many C++ compilers don't perform this optimization by default.

### Recursion vs. Iteration

Most recursive algorithms can be rewritten iteratively:

**Recursive Fibonacci**:
```cpp
int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

**Iterative Fibonacci**:
```cpp
int fibonacci_iterative(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    int fib_n_minus_2 = 0;
    int fib_n_minus_1 = 1;
    int fib_n = 0;
    
    for (int i = 2; i <= n; i++) {
        fib_n = fib_n_minus_1 + fib_n_minus_2;
        fib_n_minus_2 = fib_n_minus_1;
        fib_n_minus_1 = fib_n;
    }
    
    return fib_n;
}
```

The iterative version:
- Has constant space complexity O(1) instead of O(n) stack space
- Is typically more efficient (no function call overhead)
- But may be less intuitive for naturally recursive problems

### Recursive Palindrome Check

The palindrome check demonstrates recursion with strings:

```cpp
bool is_palindrome(const std::string &str, int start, int end) {
    // Base case: empty string or single character
    if (start >= end) {
        return true;
    }
    
    // If characters match, check the rest of the string
    if (str[start] == str[end]) {
        return is_palindrome(str, start + 1, end - 1);
    }
    
    // Characters don't match, not a palindrome
    return false;
}
```

This elegantly expresses the problem definition:
- A string is a palindrome if the first and last characters match AND
- The substring between them is also a palindrome
