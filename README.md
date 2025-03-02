# learn-you-some-cpp
Learn You Some C++ for Great Good!

## C++ Course Testing Guide

This C++ course is structured around a test-driven approach to learning. Each lesson comes with tests that validate your implementations, helping you to verify your understanding of the concepts as you progress.

### Learning Materials

The `lessons/` directory contains markdown files for each lesson with explanations of the concepts, examples, and instructions:

- [Table of Contents](#table-of-contents)

And so on...

**Read the lesson files first** to understand the concepts before attempting the implementation. The lessons will guide you through the material and give you the knowledge needed to pass the tests.

### Project Structure

The course follows a standard C++ project structure:

- **`src/`** - Contains the implementation files (`.cc`) where you'll write your code
- **`include/`** - Contains header files (`.h`) with function declarations
- **`test/`** - Contains test files that validate your implementations
- **`build/`** - Where compiled code and executables will be stored

## Example: How the Files Work Together

Let's look at the "Hello" example from Lesson 0:

#### Header File (`include/00_greet.h`)

```cpp
#ifndef GREET_H
#define GREET_H
#include <string>
std::string greet();
#endif
```

The header file declares the function `greet()` that returns a string. The `#ifndef`, `#define`, and `#endif` directives are include guards that prevent the header from being included multiple times.

#### Implementation File (`src/00_greet.cc`)

```cpp
#include "00_greet.h"
std::string greet() { return "Hello, cpp!"; }
```

The implementation file contains the actual code for the `greet()` function. It includes the header file to ensure the implementation matches the declaration.

#### Test File (`test/00_test_greet.cc`)

```cpp
#define CATCH_CONFIG_MAIN
#include "00_greet.h"
#include "catch.hpp"
TEST_CASE("Greeting returns the correct message", "[greeting]") {
  REQUIRE(greet() == "Hello, cpp!");
}
```

The test file uses the [Catch2](https://github.com/catchorg/Catch2) testing framework to verify that the `greet()` function returns the expected string. The `REQUIRE` macro checks if the condition is true.

### Testing Your Code

To test your implementations:

1. Navigate to the `build` directory:
   ```bash
   cd build
   ```

2. Generate the build files with CMake:
   ```bash
   cmake ..
   ```

3. Build the project:
   ```bash
   cmake --build .
   ```

4. Run all tests:
   ```bash
   ./run-tests
   ```

5. To run a specific test (e.g., only the greeting test):
   ```bash
   ./run-tests "[greeting]"
   ```
   The tag in square brackets corresponds to the tag in the `TEST_CASE` macro.

### Your Task

**For each lesson, you'll only need to modify:**
- The implementation files in the `src/` directory
- Occasionally, you might need to update header files in the `include/` directory

**You don't need to worry about:**
- Writing or modifying the test files - they're already written for you
- Updating the build system - the CMakeLists.txt file is already configured

### About Catch2

[Catch2](https://github.com/catchorg/Catch2) is a modern C++ testing framework. Some key features:

- Simple syntax with expressive assertion macros
- No external dependencies
- Automatic test registration
- Rich output with failure details

In the tests, you'll see:
- `TEST_CASE` - Defines a group of related tests
- `REQUIRE` - An assertion that must pass for the test to succeed
- `SECTION` - Subdivides a test case for more granular testing

### Workflow Tips

1. **Start with the lesson file** in the `lessons/` directory to learn the concepts
2. Read the test file to understand what your implementation needs to do
3. Implement the required functionality in the source file
4. Run the tests to check your solution
5. If tests fail, debug your code and try again

With this approach, the lesson materials provide the knowledge, while the tests serve both as a specification and as validation for your code, making learning more interactive and focused.

### Complete Learning Path

For each topic:

1. **Study**: Read the lesson explanation in the `lessons/` directory
2. **Understand**: Look at the test file to see what your code needs to accomplish
3. **Implement**: Write your solution in the corresponding source file
4. **Verify**: Run the tests to check if your implementation works correctly
5. **Iterate**: If needed, refine your solution until all tests pass
6. **Review**: Revisit the lesson material to ensure you've grasped all concepts


## Table of Contents
- [Lesson 0: Hello](lessons/00%20Greet.md)
- [Lesson 1: Basic Maths](lessons/01%20Basic%20Maths.md)
- [Lesson 2: Basic Strings](lessons/02%20Basic%20Strings.md)
- [Lesson 3: Basic Chars](lessons/03%20Basic%20Chars.md)
- [Lesson 4: Control Flow](lessons/04%20Control%20Flow.md)
- [Lesson 5: Basic Functions](lessons/05%20Basic%20Functions.md)
- [Lesson 6: Arrays and Memory](lessons/06%20Arrays%20and%20Memory.md)
- [Lesson 7: Pointers and References](lessons/07%20Pointers%20and%20References.md)
- [Lesson 8: Dynamic Memory](lessons/08%20Dynamic%20Memory.md)
- [Lesson 9: Bitwise](lessons/09%20Bitwise.md)
- [Lesson 10: Algorithm Basics](lessons/10%20Algorithm%20Basics.md)
- [Lesson 11: STL Containers](lessons/11%20STL%20Containers.md)
- [Lesson 12: STL Algorithms](lessons/12%20STL%20Algorithms.md)
- [Lesson 13: Custom Vectors](lessons/13%20Custom%20Vectors.md)
- [Lesson 14: Singly Linked Lists](lessons/14%20Singly%20Linked%20Lists.md)
- [Lesson 15: Doubly Linked Lists](lessons/15%20Doubly%20Linked%20Lists.md)
- [Lesson 16: Linked List Algorithms](lessons/16%20Linked%20List%20Algorithms.md)
- [Lesson 17: Recursion](lessons/17%20Recursion.md)
- [Lesson 18: Recursion Collections](lessons/18%20Recursion%20Collections.md)
- [Lesson 19: Backtracking](lessons/19%20Backtracking.md)
