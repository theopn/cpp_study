#include <iostream>
#include <string>      // for std::string
#include <string_view> // for std::string_view

/*
 * Remember that String object is passed by copy only. Use String view (read only) when passing it as a param
 */
void print_new_line(std::string_view str) {
  std::cout << str << '\n';
}

/*
 * Worse versison
 */
void print_new_line_worse(std::string str) {
  std::cout << str << '\n';
}

int main() {
  using namespace std::literals; // easiest way to access the s and sv suffixes

  print_new_line("Hello from string view"sv);
  print_new_line("Hello from string implcitly converted to SV"s); // Implicit conversion from std::string to std::string_view
  print_new_line_worse(static_cast<std::string>("Hello from string view explictly converted to string"sv)); // String view cannot be implcitly converted to write enabled string
  return 0;
}
