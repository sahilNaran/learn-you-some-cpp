## Lesson 05: Function Organization

This lesson explores how functions are organized in memory and the mechanics of function calls:

### The Call Stack

When functions call other functions, the system uses a data structure called the **call stack**:

1. When a function is called, a new **stack frame** is created, containing:
   - The return address (where to continue after the function ends)
   - The function's parameters
   - Local variables
   - Saved register values

2. As functions return, their stack frames are removed (popped)

```
Stack growth during function calls:
                    +----------------+
                    | main's locals  | <-- Stack starts here
                    +----------------+
func1 is called --> | return address |
                    | func1's params |
                    | func1's locals |
                    +----------------+
func2 is called --> | return address |
                    | func2's params |
                    | func2's locals |
                    +----------------+
```

### Namespace Implementation

Namespaces create isolated scopes for identifiers. The compiler implements this through **name mangling**:

1. The namespace becomes part of the symbol's name in the compiled code
2. For example, `temperature::to_fahrenheit` might become `_ZN11temperature13to_fahrenheitEd` in the object file
3. This prevents conflicts and allows the linker to resolve the correct function

### Default Parameters

Default parameters are processed at compile time, not runtime:

1. The compiler generates function calls with the default values filled in where missing
2. If you call `is_freezing(25.0)`, the compiler generates code equivalent to `is_freezing(25.0, true)`
3. Only trailing parameters can have defaults

```cpp
// Declaration
bool is_freezing(double temp, bool is_celsius = true);

// When you call is_freezing(25.0)
// The compiler generates this code:
bool result = is_freezing(25.0, true);
```

### Function Overloading Mechanism

Function overloading allows multiple functions with the same name but different parameters:

1. The compiler creates unique internal names based on the parameter types (name mangling)
2. For example:
   - `void print(int)` might become `_Z5printi`
   - `void print(double)` might become `_Z5printd`

3. The correct function is selected based on the **argument types** at compile time through a process called **overload resolution**

### Internal Implementation of Namespaces

In the compiled code, namespaces don't exist as runtime structures. They are purely a compile-time concept that affects name mangling and scope resolution:

```cpp
// Source code
namespace temperature {
    double to_celsius(double f) { return (f - 32) * 5 / 9; }
}

// What it effectively becomes after compilation
double _ZN11temperature10to_celsiusEd(double f) { return (f - 32) * 5 / 9; }
```
