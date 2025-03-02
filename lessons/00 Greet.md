## Lesson 00: Introduction to C++ Programming

This introductory lesson establishes the fundamental building blocks of C++ programs:

### Header Files and Implementation Files
The separation between `.h` (header) and `.cc` (implementation) files represents a core concept in C++ programming: the separation of interface from implementation. 

- **Headers** declare the "what" - they specify function signatures, class definitions, and constants that will be available to other parts of the program
- **Implementation files** define the "how" - they contain the actual code that executes when functions are called

This separation supports the principle of **information hiding**. Other parts of the program only need to know what functions do, not how they do it. When the implementation changes, as long as the interface remains the same, dependent code doesn't need to change.

### Compilation Process
When you compile a C++ program:

1. The **preprocessor** handles directives like `#include` by literally copying the content of header files into your source file
2. The `#ifndef/#define/#endif` pattern in headers creates include guards that prevent multiple inclusion of the same header
3. Each `.cc` file becomes a **compilation unit** that gets compiled independently into an **object file**
4. The **linker** combines all object files, resolving references between them

This separate compilation model allows large programs to be built incrementally, saving time during development.

### Namespaces
Namespaces like `std` provide a mechanism to prevent **name collisions** in large programs. They create a scope for identifiers, allowing the same name to be used in different contexts. For example, `std::string` indicates the `string` type from the standard library namespace.

The mechanics of namespace implementation involve prefixing symbol names with the namespace during compilation, a technique called **name mangling**.
