#include <iostream>
#define GRAVITY 9.8
int main() {
  std::cout << "Enter the height of the tower in meters: ";
  double height{};
  std::cin >> height;
  int time{0};
  double heightFallen{0};
  while (height > heightFallen) {
    std::cout << "At " << time
              << " seconds, the ball is at height: " << height - heightFallen
              << " meters" << '\n';
    heightFallen = GRAVITY * time * time / 2;
    time++;
  }
  std::cout << "At " << time + 1 << " seconds, the ball is on the ground"
            << '\n';
  return 0;
}
