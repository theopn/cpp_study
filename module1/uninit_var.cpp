#include <iostream>
void doNothing(int &) // Trick the compiler into thinking variable x is used
{}
int main() {
  int x; // this variable is defined bu uninitialized
  doNothing(
      x); // make the compiler think we're assigning a value to this variable
  std::cout << x; // print the value of x to the screen (who knows what we'll
                  // get, because x is uninitialized)
  return 0;
}
