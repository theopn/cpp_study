# Module 1

## 1.4 — Variable assignment and initialization

- Default initialization: `int a;`
- Copy initialization: `int b = 5;`
- Direct initialization: `int c( 6 );` - not used much anymore
- Brace initialization: `int d{ 7 };`
  - Value initialization: `int d = {};`

Using `[[maybe_unused]]` attribute (`-std=c++17`) will not generate unused variable warnings. E.g. `[[maybe_unused]] int x{ 5 };`

## 1.5 — Introduction to iostream: cout, cin, and endl

```cpp
#include <iostream> // for std::cout
int main() {
  int a{5}; // define integer variable x, initialized with value 5
  // std::cout << "Hi!" << std::endl; // std::endl will cause the cursor to move to the next line of the console - Flush result immediately
  std::cout << "Hi!" << '\n'; // Prefer '\n' over std::endl
  std::cout << "a is equal to: " << a << '\n'; // print value of x (5) to console

  std::cout << "Enter two numbers separated by a space: ";
  int x{}; // define variable x to hold user input (and zero-initialize it)
  int y{}; // define variable y to hold user input (and zero-initialize it)
  std::cin >> x >> y; // get two numbers and store in variable x and y respectively
  std::cout << "You entered " << x << " and " << y << '\n';

  return 0;
}
```

Remember that `cin` will do some error handling by itself. For the above program, if character or string is input, the x or y is 0. If float is input, it will truncate. If `123abc` is input, it will be set to `123`.

## 

```cpp
#include <iostream>
void doNothing(int&) // Trick the compiler into thinking variable x is used
{}
int main() {
    int x; // this variable is defined bu uninitialized
    doNothing(x); // make the compiler think we're assigning a value to this variable
    std::cout << x; // print the value of x to the screen (who knows what we'll get, because x is uninitialized)
    return 0;
}
```

## 1.8 — Whitespace and basic formatting

```cpp
#include <iostream>
int main() {
  std::cout << "Hello"
               " world!"
            << '\n'; // Prints out Hello world!\n
}
```

## 1.9 — Introduction to literals and operators

- Unary operators: Act on one operand `-5`
- Binary operators: Act on two operands, known as *left* and *right* `3 + 4`
- Ternary operators: Act on three operands, only one in C/C++ `(condition) ? (x) : (y)`
- Nullary operators: Act on zero operands, only one in C++ `throw`

