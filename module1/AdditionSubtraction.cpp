#include <iostream>

/**
 * Module 1 Final Project
 */
int main(int argc, char *argv[]) {
  std::cout << "Enter an intger: ";
  int num{};
  std::cin >> num;
  std::cout << "Enter another intger: ";
  int another_num{};
  std::cin >> another_num;

  std::cout << num << " + " << another_num << " is " << num + another_num
            << '\n'
            << num << " - " << another_num << " is " << num - another_num
            << '\n';
  return 0;
}
