# Module 6

## 6.2 — User-defined namespaces and the scope resolution operator

```cpp
#include <iostream>

int func(int x, int y) { return x * y; }

namespace foo {
  int func(int x, int y) { return x + y; }
}

namespace bar {
  int func(int x, int y) { return x - y; }

  int funcfunc() {
    std::cout << ::func(10, 10) << '\n'; // Global func is used -> 10 * 10
    std::cout << func(10, 10) << '\n'; // Same as bar::func(10, 10) -> 10 - 10
  }
}

int main() {
  std::cout << ::func(5, 5) << '\n'; // 25
  std::cout << foo::func(5, 5) << '\n'; // 10
  std::cout << bar::func(5, 5) << '\n'; // 0

  bar::funcfunc(); // 100\n0\n\0
}
```

Nested namespace:

```cpp
#include <iostream>

namespace foo::goo { // same as namespace foo { namespace goo { // stuff } }
  int add(int x, int y) {
      return x + y;
  }
}

int main() {
  namespace active = foo::goo; // active now refers to foo::goo
  std::cout << active::add(1, 2) << '\n'; // This is really foo::goo::add()
  return 0;
} // The active alias ends here
```

## 6.5 — Variable shadowing (name hiding)

```cpp
#include <iostream>
// Keep in mind that the best practice is to avoid variable shadowing
int main() {
  int x{5};
  {
    std::cout << x << '\n'; // Prints out 5
    int x{10}; // Outer 'x' is shadowed. In this block, the 'x' that we just defined will be used
    std::cout << x << '\n'; // Prints out 10
  }
  std::cout << x << '\n'; // The 'x' in the block above is inaccessible. Prints out 5
  return 0;
}
```

## 6.6 — Internal linkage

```cpp
// Internal global variables definitions:
static int g_x;          // defines non-initialized internal global variable (zero initialized by default)
static int g_x{ 1 };     // defines initialized internal global variable

const int g_y { 2 };     // defines initialized internal global const variable
constexpr int g_y { 3 }; // defines initialized internal global constexpr variable

// Internal function definitions:
static int foo() {};     // defines internal function
```

## 6.7 — External linkage and variable forward declarations

```cpp
// External global variable definitions:
int g_x;                       // defines non-initialized external global variable (zero initialized by default)
extern const int g_x{ 1 };     // defines initialized const external global variable
extern constexpr int g_x{ 2 }; // defines initialized constexpr external global variable

// Forward declarations
extern int g_y;                // forward declaration for non-constant global variable
extern const int g_y;          // forward declaration for const global variable
extern constexpr int g_y;      // not allowed: constexpr variables can't be forward declared
```

## 6.8 — Why (non-const) global variables are evil

I hope that the chapter title and your programming experience make this question obvious :(

```cpp
namespace constants {
  constexpr double gravity { 9.8 }; // has internal linkage, is accessible only by this file
}

double getGravity() { // this function can be exported to other files to access the global outside of this file
  // We could add logic here if needed later
  // or change the implementation transparently to the callers
  return constants::gravity;
}
```

## 6.9 — Sharing global constants across multiple files (using inline variables)

`constants.h`:

```cpp
#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants {
  // since the actual variables are inside a namespace, the forward declarations need to be inside a namespace as well
  extern const double pi;
  extern const double avogadro;
  extern const double myGravity;
}

#endif
```

`constants.cpp`:

```cpp
#include "constants.h"

namespace constants {
  // actual global variables
  extern const double pi { 3.14159 };
  extern const double avogadro { 6.0221413e23 };
  extern const double myGravity { 9.2 }; // m/s^2 -- gravity is light on this planet
}
```

`main.cpp`:

```cpp
#include "constants.h" // include all the forward declarations

#include <iostream>

int main() {
  std::cout << "Enter a radius: ";
  int radius{};
  std::cin >> radius;
  std::cout << "The circumference is: " << 2.0 * radius * constants::pi << '\n';
  return 0;
}
```

Why not initialize variables in the `constants.h` (e.g. `constexpr double pi { 3.14159 }`)? That works, but that would require recompilation of every files that include `constants.h` whenever we change the constant. Also remember to use `std::string_view` for any constant strings!

## 6.10 — Static local variables

Just like in C, only use `static` when it does not need to be reset.

## 6.12 — Using declarations and using directives

Do not use `using declarations` (such as `using std::cout; cout << "No don't do this";`) or `using directives` (except for `using namespace std::literals`). If you really want to, use it inside of a block.

```cpp
int main() {
  {
    using namespace foo;
    // foo related stuff. There is no way to cancel using namespace foo in this block
  }

  {
    using namespace bar;
  }
  return 0;
}
```

## 6.13 — Inline functions

`inline` keyword exists and expands the function body as a compile-time expression. It could be a double-edged sword though, if there is more function call in the inline expression than the original function.

## 6.14 — Constexpr and consteval functions

```cpp
#include <type_traits> // for std::is_constant_evaluated - only in C++20
#include <iostream>

// In C++20, you can use the keyword is_consteval, which tells the compiler that the func must be eval at compile or error
constexpr int greater(int x, int y) {
  return (x > y ? x : y);
}

int main() {
  constexpr int x{ 5 };
  constexpr int y{ 6 };

  constexpr int g { greater(x, y) }; // will be evaluated at compile-time

  std::cout << g << " is greater!\n";

  if (std::is_constant_evaluated()) // if compile-time evaluation
      // do something
  else // runtime evaluation
      // do something else
  return 0;
}
```

## 6.15 — Unnamed and inline namespaces

Unnamed namespace is basically same as marking stuff as static (only be used in the file):

```cpp
#include <iostream>

namespace { // unnamed namespace
  void doSomething() { // can only be accessed in this file. Same as doing static void doSomething()
    std::cout << "v1\n";
  }
}

int main(){
  doSomething(); // we can call doSomething() without a namespace prefix
  return 0;
}
```

Inline namespace lets you declare namespace statically

```cpp
#include <iostream>

namespace v1 { // declare a normal namespace named v1
  void doSomething() {
    std::cout << "v1\n";
  }
}

inline namespace v2 { // declare an inline namespace named v2
  void doSomething() {
    std::cout << "v2\n";
  }
}

int main() {
  v1::doSomething(); // calls the v1 version of doSomething()
  v2::doSomething(); // calls the v2 version of doSomething()

  doSomething(); // calls the inline version of doSomething() (which is v2)

  return 0;
}
```

