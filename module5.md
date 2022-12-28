# 5.3 — Modulus and Exponentiation

- Float exponent: `std::pow(x, y)`

I will add this custom integer exponent function to introduce the C-style assert:

```cpp
#include <iostream>
#include <cstdint> // for std::int64_t
#include <cassert> // for assert

// note: exp must be non-negative
std::int64_t powint(std::int64_t base, int exp) {
  assert(exp >= 0 && "powint: exp parameter has negative value");

  std::int64_t result{ 1 };
  while (exp) {
    if (exp & 1)
      result *= base;
    exp >>= 1;
    base *= base;
  }
  return result;
}
```

## 5.4 — Increment/decrement operators, and side effects

> Strongly favor the prefix version of the increment and decrement operators (`++x` over `x++`), as they are generally more performant, and you’re less likely to run into strange issues with them.

Side effect:

```cpp
...
int x{ 5 };
int value{ add(x, ++x) }; // is this 5 + 6, or 6 + 6? - Depends on compiler
...
```

## 5.5 — Comma and conditional operators

```cpp
#include <iostream>

int main() {
  int x{ 1 };
  int y{ 2 };

  std::cout << (++x, ++y) << '\n'; // increment x and y, evaluates to the right operand. Print 3 (++y)

  return 0;
}
```

Conditional operator - Remember to put parenthesis:

```cpp
...
int x{ 5 };
std::cout << (x != 6) ? x : 7; // This is (std::cout << (x != 6)) ? x : 7; - meaning it will print out 1 (true) or 0 (false)
std::cout << '\n';
std::cout << ((x != 6) ? (x) : (7))); // This is better. Thanks Dr. Turkstra for teaching this in 240
```

## 5.6 — Relational operators and floating point comparisons

It is okay to compare low-precision (few significant digit) float (`GRAVITY {9.8}; if (9.8 == GRAVITY) {}`). However, in general, you should make a custom function using epsilon:

```cpp
#include <algorithm> // std::max
#include <cmath> // for std::abs()
// epsilon is an absolute value
bool approximately_equal_abs(double a, double b, double abs_epsilon) {
  // if the distance between a and b is less than absEpsilon, then a and b are "close enough"
  return std::abs(a - b) <= abs_epsilon;
}

// return true if the difference between a and b is within epsilon percent of the larger of a and b
bool approximately_equal_rel(double a, double b, double rel_epsilon) {
  // Take percentage close (0.001, 0.002, etc) as the rel_epsilon
  return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * rel_epsilon));
}

// Best version
// return true if the difference between a and b is less than absEpsilon, or within relEpsilon percent of the larger of a and b
bool approximately_equal_abs_rel(double a, double b, double abs_epsilon, double rel_epsilon) {
  // Check if the numbers are really close -- needed when comparing numbers near zero.
  double diff{ std::abs(a - b) };
  if (diff <= abs_epsilon)
      return true;

  // Otherwise fall back to Knuth's algorithm
  return (diff <= (std::max(std::abs(a), std::abs(b)) * rel_epsilon));
}
```

## 5.7 — Logical operators

De Morgan's law:

- !(x && y) is equivalent to !x || !y
- !(x || y) is equivalent to !x && !y

Mimicking XOR:

```cpp
if (a != b != c != d) ... // a XOR b XOR c XOR d, assuming a, b, c, and d are Booleans
if (((a != b) != c) != d) // Same as above
```

## 5.x — Chapter 5 summary and quiz

Question #1: Evaluate the following:

1. (5 > 3 && 4 < 8) // True and true == true
2. (4 > 6 && true) // False and true == false
3. (3 >= 3 || false) // True or false == true
4. (true || false) ? 4 : 5 // if (true) 4; else 5; Therefore 4

Question #3: Why should you never do the following:

1. int y{ foo(++x, x) }; // ++x side effect, compiler might choose to use the result of ++x for the x or x before ++ operator
2. double x{ 0.1 + 0.1 + 0.1 }; return (x == 0.3); // Float addition introduces rounding error, so it will likely return false
3. int x{ 3 / 0 }; // Dividing by zero

