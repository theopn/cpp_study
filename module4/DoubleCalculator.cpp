#include <iostream>

double getDoubleVal() {
  std::cout << "Enter a double value: ";
  double x{};
  std::cin >> x;
  return x;
}

int main() {
  double x{};
  x = getDoubleVal();
  double y{};
  y = getDoubleVal();

  std::cout << "Enter one of the following: +, -, *, or /: ";
  char operation{};
  std::cin >> operation;
  switch (operation) {
  case '+':
    std::cout << x << " + " << y << " is " << x + y;
    break;
  case '-':
    std::cout << x << " - " << y << " is " << x - y;
    break;
  case '*':
    std::cout << x << " * " << y << " is " << x * y;
    break;
  case '/':
    std::cout << x << " / " << y << " is " << x / y;
  }
  std::cout << '\n';

  return 0;
}
