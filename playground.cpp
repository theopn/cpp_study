#include <iostream>

#define ENABLE_DEBUGGING 1
#define DBG_STREAM                                                             \
  if (!ENABLE_DEBUGGING) {                                                     \
  } else                                                                       \
    std::cerr

int main() {
  DBG_STREAM << "Debugging enabled\n";
  return 0;
}
