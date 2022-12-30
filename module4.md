# Module 4

## 4.3 — Object sizes and the sizeof operator

```cpp
#include <iostream>
int main() {
  std::cout << "bool:\t\t" << sizeof(bool) << " bytes\n";
  std::cout << "char:\t\t" << sizeof(char) << " bytes\n";
  std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes\n";
  std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes\n";
  std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes\n";
  std::cout << "short:\t\t" << sizeof(short) << " bytes\n";
  std::cout << "int:\t\t" << sizeof(int) << " bytes\n";
  std::cout << "long:\t\t" << sizeof(long) << " bytes\n";
  std::cout << "long long:\t" << sizeof(long long) << " bytes\n";
  std::cout << "float:\t\t" << sizeof(float) << " bytes\n";
  std::cout << "double:\t\t" << sizeof(double) << " bytes\n";
  std::cout << "long double:\t" << sizeof(long double) << " bytes\n";

    return 0;
}
```

## 4.5 — Unsigned integers, and why to avoid them

Signed/unsigned mismatch:

```cpp
#include <iostream>
int main() {
  signed int s { -1 };
  unsigned int u { 1 };

  if (s < u) // -1 is implicitly converted to 4294967295, and 4294967295 < 1 is false
    std::cout << "-1 is less than 1\n";
  else
    std::cout << "1 is less than -1\n"; // this statement executes

  return 0;
}
```

## 4.6 — Fixed-width integers and size_t

Fixed-width integers and fast/least integers:

```cpp
include <cstdint> // for fixed-width integers
#include <iostream>

int main() {
  std::int16_t i{5}; // 1. Might not be defined in all arch 2. Might be slower
  // Smallest signed/unsigned integer type with a width of at least x bits
  std::cout << "least 8:  " << sizeof(std::int_least8_t) * 8 << " bits\n";
  std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
  std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
  std::cout << '\n';
  // Fastest signed/unsigned integer type with a width of at least x bits
  std::cout << "fast 8:  " << sizeof(std::int_fast8_t) * 8 << " bits\n";
  std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
  std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";
  return 0;
}
```

`sizeof()` returns `std::size_t`

## 4.8 — Floating point numbers

Rounding error:

```cpp
#include <iomanip> // for std::setprecision()
#include <iostream>
int main() {
  float f { 123456789.0f }; // f has 10 significant digits
  std::cout << std::setprecision(9); // to show 9 digits in f
  if (f == 123456789) {
    std::cout << "You know this will never happen";
  } else {
    std::cout << f << '\n'; // Will print out 123456792
  }
  return 0;
}
```

NaN and infinity:

```cpp
#include <iostream>

int main() {
  double posinf { 5.0 / 0.0 };
  std::cout << posinf << '\n'; // Prints out "inf"

  double neginf { -5.0 / 0.0 };
  std::cout << neginf << '\n'; // Prints out "-inf"

  double nan { 0.0 / 0.0 };
  std::cout << nan << '\n'; // Prints out "nan"

  return 0;
}
```

## 4.9 — Boolean values

Non-zero integer values are all true (1).

`std::boolalpha`:

```cpp
#include <iostream>
int main() {
  std::cout << true << '\n'; // "1\n\0"
  std::cout << false << '\n'; // "0\n\0"
  std::cout << std::boolalpha;
  std::cout << true << '\n'; // "true\n\0"
  std::cout << false << '\n'; // "false\n\0"
  return 0;
}
```

## 4.11 — Chars

Similar to all other I/O scanners, char graps queued input:

```cpp
#include <iostream>

int main() {
  std::cout << "Input multiple character: "; // assume the user enters "abcd" (without quotes)
  char ch{};
  std::cin >> ch; // ch = 'a', "bcd" is left queued.
  std::cout << "You entered: " << ch << '\n';

  // Note: The following cin doesn't ask the user for input, it grabs queued input!
  std::cin >> ch; // ch = 'b', "cd" is left queued.
  std::cout << "You entered: " << ch << '\n';
  return 0;
}
```

Some escape sequences:

- `\(number)`: Translates into char represented by octal
- `\x(number)`: Translates into char represented by hex number

## 4.12 — Introduction to type conversion and static_cast

`static_cast`, which is same as `(type)` casting in C but safer:

```cpp
#include <iostream>

int main() {
  unsigned int u { 5u }; // 5u means the number 5 as an unsigned int
  int s { static_cast<int>(u) }; // return value of variable u as an int

  std::cout << s;
  return 0;
}
```

## 4.13 — Const variables and symbolic constants

```cpp
#define SYMBOLIC_CONSTANT_EARTH_GRAVITY 9.8
int main() {
  const double k_earth_gravity { 9.8 }; // Remember that const must be initialized at definition
  return 0;
}
```

## 4.14 — Compile-time constants, constant expressions, and constexpr

```cpp
#include <iostream>
int getNumber() {
  int y { };
  std::cin >> y;
  return y;
}
int main() {
  constexpr double k_earth_gravity { 4.8 + 5.0 }; // This is okay, value known at the compile time
  constexpr int k_regular_const { getNumber() }; // Not okay, value not known at the compile time. Use regular const
  return 0;
}
```

## 4.16 — Numeral systems (decimal, binary, hexadecimal, and octal)

Digit separator (purely visual):
```cpp
#include <bitset> // for std::bitset
int main() {
  long value { 2'132'673'462 }; // much easier to read than 2132673462
  std::bitset<8> bin1{ 0b1100'0101 }; // binary literal for binary 1100 0101
}
```

## 4.17 — Introduction to std::string

```cpp
#include <string> // allows use of std::string
#include <iostream>
int main() {
  int age {};
  std::cout << "Enter your age: ";
  std::cin >> age;

  std::string name {};
  std::cout << "Enter your name: ";
  std::getline(std::cin >> std::ws, name); // cin only reads up to the first white space. std::ws will also ignore leading whitespace

  std::cout << "Your name is " << name << " and " << age << " years old" << '\n';
  // Casting is not necessary, but remember length() returns size_t so when assigning to a var, you need to do it
  std::cout << "Your name is " << static_cast<int>(name.length()) << " characters long" << '\n';
  //std::cout << "Your name is " << std::ssize(name) << " characters long" << '\n'; // Supported in C++20
  return 0;
}
```

## 4.18 — Introduction to std::string_view

```cpp
#include <iostream>
#include <string>      // for std::string
#include <string_view> // for std::string_view

/*
 * Remember that String object is passed by copy only. Use String view (read only) when passing it as a param
 */
void printNewLine(std::string_view str) {
  std::cout << str << '\n';
}

/*
 * Worse versison
 */
void worsePrintNewLine(std::string str) {
  std::cout << str << '\n';
}

int main() {
  using namespace std::literals; // easiest way to access the s and sv suffixes

  printNewLine("Hello from string view"sv);

  // Implicit conversion from std::string to std::string_view
  printNewLine("Hello from string implcitly converted to SV"s);

  // String view cannot be implcitly converted to write enabled string
  worsePrintNewLine(static_cast<std::string>("Hello from string view explictly converted to string"sv));
  return 0;
}
```

