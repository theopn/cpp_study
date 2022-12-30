#include <iostream>

/*
 * Complete the following program by writing the passOrFail() function, which
 * should return true for the first 3 calls, and false thereafter. Do this
 * without modifying the main() function.
 */
bool passOrFail() {
  static int count{0};
  count++;
  return (count > 3);
}

int main() {
  std::cout << "User #1: " << (passOrFail() ? "Pass\n" : "Fail\n");
  std::cout << "User #2: " << (passOrFail() ? "Pass\n" : "Fail\n");
  std::cout << "User #3: " << (passOrFail() ? "Pass\n" : "Fail\n");
  std::cout << "User #4: " << (passOrFail() ? "Pass\n" : "Fail\n");
  std::cout << "User #5: " << (passOrFail() ? "Pass\n" : "Fail\n");

  return 0;
}
