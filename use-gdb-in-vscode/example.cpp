#include <iostream>

void func3() {
  int i3 = 3;
  std::cout << i3 << std::endl;
}

void func2() {
  int i2 = 2;
  std::cout << i2 << std::endl;
  func3();
}

void func1() {
  int i1 = 1;
  std::cout << i1 << std::endl;
  func2();
}

int main() {
  int i0 = 0;
  std::cout << i0 << std::endl;
  func1();
  return 0;
}