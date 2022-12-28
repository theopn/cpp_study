#include <iostream>
#include <string>      // for std::string
#include <string_view> // for std::string_view

int main() {
  int x{5};
  std::cout << (x != 6) ? x : 7;
  std::cout << '\n';
  std::cout << ((x != 6) ? (x) : (7));

  return 0;
}
