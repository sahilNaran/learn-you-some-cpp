## Lesson 19: Backtracking Algorithms

This lesson explores a powerful technique for solving constraint satisfaction and combinatorial problems:

### Backtracking Paradigm

Backtracking is a systematic way to explore a search space:
1. Make a choice (place an item, make a selection)
2. Recursively solve the remaining subproblem
3. If the solution fails, undo the choice (backtrack) and try another option

```
General backtracking pattern:
function backtrack(current_state, remaining_choices):
    if is_solution(current_state):
        save_or_return_solution()
        return
        
    for choice in remaining_choices:
        if is_valid(current_state, choice):
            apply_choice(current_state, choice)
            backtrack(current_state, updated_remaining_choices)
            undo_choice(current_state, choice)  // Backtrack
```

### Generating Permutations

Permutation generation demonstrates backtracking:

```cpp
void generate_permutations(std::string &str, int start, int end,
                           std::vector<std::string> &result) {
    // Base case: all positions have been decided
    if (start == end) {
        result.push_back(str);
        return;
    }
    
    // Try each possibility for the current position
    for (int i = start; i <= end; i++) {
        // Make a choice: place character at index i in position start
        std::swap(str[start], str[i]);
        
        // Recursively generate permutations for remaining positions
        generate_permutations(str, start + 1, end, result);
        
        // Backtrack: undo the choice
        std::swap(str[start], str[i]);
    }
}
```

This systematically:
1. For each position, try all possible characters
2. For each choice, recursively arrange the remaining positions
3. After exploring each option, restore the original state (backtrack)

The time complexity is O(n!), matching the number of permutations.

### Subset Generation

Generating all subsets shows a different backtracking pattern:

```cpp
void generate_subsets(const std::vector<int> &nums, int index,
                      std::vector<int> &current,
                      std::vector<std::vector<int>> &result) {
    // Base case: processed all elements
    if (index == nums.size()) {
        result.push_back(current);
        return;
    }
    
    // Option 1: Include the current element
    current.push_back(nums[index]);
    generate_subsets(nums, index + 1, current, result);
    
    // Option 2: Exclude the current element (backtrack)
    current.pop_back();
    generate_subsets(nums, index + 1, current, result);
}
```

For each element, we make a binary choice (include or exclude), resulting in 2^n possible subsets.

### N-Queens Problem

The N-Queens problem is a classic backtracking example:

```cpp
bool solve_n_queens(std::vector<int> &board, int col, int n) {
    // Base case: all queens placed
    if (col == n) {
        return true;
    }
    
    // Try placing queen in each row of current column
    for (int row = 0; row < n; row++) {
        if (is_safe(board, row, col)) {
            // Place queen
            board[col] = row;
            
            // Recursively place rest of queens
            if (solve_n_queens(board, col + 1, n)) {
                return true;
            }
            
            // Backtrack: remove queen
            board[col] = -1;
        }
    }
    
    return false;  // No solution found
}

bool is_safe(const std::vector<int> &board, int row, int col) {
    // Check previous columns
    for (int prev_col = 0; prev_col < col; prev_col++) {
        // Check same row
        if (board[prev_col] == row) {
            return false;
        }
        
        // Check diagonals
        if (std::abs(board[prev_col] - row) == std::abs(prev_col - col)) {
            return false;
        }
    }
    
    return true;
}
```

This algorithm:
1. Tries placing a queen in each row of the current column
2. For each valid placement, recursively tries to place queens in remaining columns
3. If no solution is found, backtracks and tries a different row

The time complexity is O(n!), but pruning invalid configurations reduces the actual computations significantly.

### Sudoku Solver

Sudoku solving showcases constrained backtracking:

```cpp
bool solve_sudoku(std::vector<std::vector<int>> &board) {
    // Find an empty cell
    std::pair<int, int> empty_cell = find_empty(board);
    int row = empty_cell.first;
    int col = empty_cell.second;
    
    // No empty cells left, puzzle solved
    if (row == -1 && col == -1) {
        return true;
    }
    
    // Try digits 1-9
    for (int num = 1; num <= 9; num++) {
        if (is_valid(board, row, col, num)) {
            // Place the digit
            board[row][col] = num;
            
            // Recursively solve the rest
            if (solve_sudoku(board)) {
                return true;
            }
            
            // Backtrack: remove the digit
            board[row][col] = 0;
        }
    }
    
    return false;  // No solution found
}
```

This algorithm:
1. Finds an empty cell
2. Tries each valid digit (1-9) in that cell
3. For each placement, recursively attempts to solve the remaining puzzle
4. If a placement leads to an invalid board, backtracks and tries a different digit

### Pruning Techniques

Effective backtracking uses pruning to eliminate unproductive branches:

1. **Early termination**: Recognize invalid partial solutions before exploring them fully
2. **Constraint propagation**: Use constraints to reduce the search space
3. **Ordering heuristics**: Choose decisions that are more likely to lead to solutions first
4. **Symmetry breaking**: Avoid exploring equivalent configurations

These techniques can dramatically reduce the effective search space and make otherwise intractable problems solvable.

### Exponential Time Complexity

Most backtracking algorithms have exponential time complexity:
- Permutations: O(n!)
- Subsets: O(2^n)
- N-Queens: O(n!)
- Sudoku: O(9^(n²)) in the worst case

Despite this exponential behavior, backtracking is often practical because:
1. Pruning dramatically reduces the actual explored space
2. Many problem instances have structure that leads to solutions quickly
3. For some problems, no polynomial-time algorithms exist (NP-complete problems)

Backtracking represents a general approach to systematically explore large solution spaces while avoiding brute-force enumeration of all possibilities.
