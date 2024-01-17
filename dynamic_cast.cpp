// dynamic_cast
// SYNTAX: dynamic_cast <new_type> (expression)

/**
 * 1. dynamic_cast is used at runtime to find out correct downcast.
 * NOTE0: Need at least one virtual function in base class.
 * NOTE1: If the cast is successful, dynamic_cast returns a value of type
 *        new_type.
 * NOTE2: If the cast fails and new_type is a pointer type, it returns
 *        a null pointer of that type.
 * NOTE3: If the cast fails and new_type is a reference type, it throws an
 *        exception that matches a handler of type std::bad_cast.
 */

#include <cassert>
#include <iostream>

class Base {
  // try the non virtual version
  // void print() { std::cout << "Base" << std::endl; }
  virtual void print() { std::cout << "Base" << std::endl; }
};

class Derived1 : public Base {
  void print() { std::cout << "Derived1" << std::endl; }
};

class Derived2 : public Base {
  void print() { std::cout << "Derived2" << std::endl; }
};

int main() {
  Derived1 d1;

  {
    Base *bp = dynamic_cast<Base *>(&d1);
    Derived2 *d2 = dynamic_cast<Derived2 *>(bp);
    assert(d2 == nullptr);
  }

  {
    Base &br = dynamic_cast<Base &>(d1);
    Derived2 &d2 = dynamic_cast<Derived2 &>(br); // throws std::bad_cast
  }

  return 0;
}

// if we are sure that the cast will succeed, we should use static_cast