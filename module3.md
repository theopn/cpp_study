# Module 3

## 3.5 — More debugging tactics

Conditional debugging:

```cpp
#include <iostream>

#define ENABLE_DEBUGGING 1
#define DBG_STREAM \
  if (!ENABLE_DEBUGGING) { }\
  else std::cerr

int main() {
  DBG_STREAM << "Debugging enabled\n";
  return 0;
}
```

## Some interesting question in the quiz

What does the call stack look like in the following program when the point of execution is on line 4? Only the function names are needed for this exercise, not the line numbers indicating the point of return.

```cpp
#include <iostream>

void d()
{ // here
}

void c()
{
}

void b()
{
  c();
  d();
}

void a()
{
  b();
}

int main()
{
  a();

  return 0;
}
```

d - b - a - main

