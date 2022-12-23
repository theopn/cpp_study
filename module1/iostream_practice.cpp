#include <iostream> // for std::cout
int main() {
  int a{5}; // define integer variable x, initialized with value 5
  // std::cout << "Hi!" << std::endl; // std::endl will cause the cursor to move
  // to the next line of the console - Flush result immediately
  std::cout << "Hi!" << '\n'; // Prefer '\n' over std::endl
  std::cout << "a is equal to: " << a
            << '\n'; // print value of x (5) to console

  std::cout << "Enter two numbers separated by a space: ";
  int x{}; // define variable x to hold user input (and zero-initialize it)
  int y{}; // define variable y to hold user input (and zero-initialize it)
  std::cin >> x >>
      y; // get two numbers and store in variable x and y respectively
  std::cout << "You entered " << x << " and " << y << '\n';

  return 0;
}
