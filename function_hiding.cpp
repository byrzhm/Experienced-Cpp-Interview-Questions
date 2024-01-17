#include <iostream>

class Base {
public:
  void func(int i) { std::cout << "Base: " << i << std::endl; }
};

class Derived : public Base {
public:
  using Base::func; // ! overcome function hiding
  void func(char c) { std::cout << "Derived: " << c << std::endl; }
};

int main() {
  Derived d;
  d.func('c');
  d.func(0x30);
  // d.Base::func(0x30);
  return 0;
}