# Module 2

## 2.9 — Naming collisions and an introduction to namespaces

- Explicit namespace qualifier: `std:cout`
- Namespace directive: Avoid...

```cpp
#include <iostream>
using namespace std;

int cout() { // This will collide with the global namespace. Avoid using this
  return -1;
}
int main() {
  cout << "Hello world\n";
  return 0;
}
```

## 2.10 — Introduction to the preprocessor

Conditional compilation:

```cpp
#include <iostream>

#define PRINT_JOE
#define FOO 9

int main() {
#ifdef PRINT_JOE
    std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
#endif

#ifdef PRINT_BOB
  std::cout << "Bob\n"; // will be ignored since PRINT_BOB is not defined
#endif

#ifndef PRINT_BOB // "ifndef" is opposite of "ifdef"
  std::cout << "Bob not defined\n"; // will be compiled since PRINT_BOB is not defined
#endif

#if 0
  // Code that you don't want to be compiled
#endif

#ifdef FOO
  std::cout << FOO << '\n'; // Will print out '9'
#endif

#if FOO < 4
  std::cout << FOO << '\n'; // Will also print out '9'
#endif

    return 0;
}
```

## 2.12 — Header guards

square.h:

```cpp
#ifndef _SQUARE_H_
#define _SQUARE_H_

int get_square_sides() {
  return 4;
}

#endif
```

geometry.h:

```cpp
#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include "square.h"

#endif
```

main.cpp:

```cpp
#include "square.h"
#include "geometry.h"

int main() {
  return 0;
}
```

