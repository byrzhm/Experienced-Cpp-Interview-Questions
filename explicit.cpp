#include <iostream>

class Base {
  int i;

public:
  Base() = default;
  // Base(int i) : i(i) {}
  explicit Base(int i) : i(i) {}
  void print() { std::cout << "Base: " << i << std::endl; }
};

void func(Base b) { b.print(); }

int main() {
  Base obj1(10); // explicit constructor call
  // Base obj2 = 20; // implicit constructor call

  func(obj1); // explicit call to copy constructor
  // func(30);   // implicit call to constructor

  return 0;
}