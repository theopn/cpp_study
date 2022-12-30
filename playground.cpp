#include <iostream>

int func(int x, int y) { return x * y; }

namespace foo {
int func(int x, int y) { return x + y; }
} // namespace foo

namespace bar {
int func(int x, int y) { return x - y; }

void funcfunc() {
  std::cout << ::func(10, 10) << '\n'; // Global func is used -> 10 * 10
  std::cout << bar::func(10, 10)
            << '\n'; // Same as bar::func(10, 10) -> 10 - 10
}
} // namespace bar

int main() {
  std::cout << ::func(5, 5) << '\n';    // 25
  std::cout << foo::func(5, 5) << '\n'; // 10

  bar::funcfunc();
}
