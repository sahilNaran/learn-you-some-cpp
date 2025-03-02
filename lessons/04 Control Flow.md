## Lesson 04: Control Flow

This lesson explores how program execution path is controlled and the underlying mechanisms:

### How CPU Implements Branches

When the CPU encounters conditional statements like `if`, it follows these steps:

1. The condition is evaluated, setting status flags (like "is zero", "is negative", etc.)
2. Based on these flags, the CPU decides whether to continue executing the next instruction or jump to a different location in memory
3. If the condition is true, the CPU changes its instruction pointer to the address of the target code
4. If false, the CPU continues with the next instruction in sequence

Think of it like a fork in the road where the CPU needs to decide which path to follow based on the condition:

```
Conceptual representation of an if statement:
                            ┌─── If condition is false ───┐
                            │                             ▼
Start ──> Evaluate condition ───> If condition is true ───> if-block code ──> Continue
                                                                                 ▲
                                                                                 │
                                         else-block code ───────────────────────┘
```

**Branch Prediction**:
Modern CPUs use sophisticated branch prediction to guess which path will be taken and speculatively execute instructions, improving performance when predictions are correct. This is like the CPU making an educated guess about which fork in the road you'll take before you actually decide.

### Loop Implementation

Different loop types have different memory layouts and performance characteristics:

**For loops**:
A for loop follows this execution pattern:
1. Initialize a counter variable
2. Check if the counter meets the exit condition
3. If the exit condition is false, execute the loop body
4. Update the counter
5. Return to step 2

You can visualize this as a cycle:

```
┌─────────────────┐
│                 │
│ Initialize      │
│ counter         │
│                 │
└────────┬────────┘
         │
         ▼
┌─────────────────┐     No     ┌─────────────────┐
│                 │            │                 │
│ Check exit      │───────────▶│ Execute loop    │
│ condition       │            │ body            │
│                 │            │                 │
└────────┬────────┘            └────────┬────────┘
         │                              │
         │ Yes                          │
         ▼                              │
┌─────────────────┐                     │
│                 │                     │
│ Exit loop       │                     │
│                 │      ┌─────────────┐│
└─────────────────┘      │             ▼
                         │   ┌─────────────────┐
                         │   │                 │
                         └───┤ Update counter  │
                             │                 │
                             └─────────────────┘
```

**While loops**:
Similar to for loops but with the initialization outside the loop structure. The condition is checked before the loop body executes.

**Do-while loops**:
Guarantee at least one execution of the loop body before checking the condition. The condition is checked after the loop body executes.

### Factorial Calculation Analysis

The factorial function demonstrates how loops handle mathematical sequences:

```cpp
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for(int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
```

**Time Complexity**: O(n) - we perform n-1 multiplications
**Space Complexity**: O(1) - we use a fixed amount of memory regardless of input size

**Numerical Considerations**:
- Factorial values grow extremely quickly (faster than exponential)
- For n > 20, a 64-bit unsigned long long will overflow
- Large factorials require arbitrary-precision arithmetic libraries

### Switch Statement Implementation

Under the hood, `switch` statements can be implemented in different ways:

1. **Jump table** (for dense, small ranges of values):
   - The compiler creates an array where each entry points to a case block
   - The switch value is used as an index into this array
   - The CPU directly jumps to the appropriate code section
   - Very fast O(1) time regardless of number of cases

Here's a visualization of a jump table:
```
switch(value) {
    case 0: code_block_0; break;
    case 1: code_block_1; break;
    case 2: code_block_2; break;
}

Jump table:
┌───────────────┬───────────────┬───────────────┐
│ If value = 0  │ If value = 1  │ If value = 2  │
│ go to block 0 │ go to block 1 │ go to block 2 │
└───────────────┴───────────────┴───────────────┘
```

2. **Binary search of labels** (for sparse or large ranges):
   - For non-sequential case values (like 1, 100, 200), a jump table would waste memory
   - The compiler generates code that performs a binary search among the case values
   - O(log n) time where n is the number of cases

For example, with cases 1, 50, and 100, the compiler generates code that first checks if the value is less than 50, then either checks against 1 or 100 based on that result.
