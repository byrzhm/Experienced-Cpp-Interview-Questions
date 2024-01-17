// 问题: 引用与指针的区别
// 回答: 见代码

#include <iostream>

int main() {
  int i = 10;

  int &r = i;
  int *p = &i;

  // 1. Memory address
  std::cout << "address of i: " << &i << '\n';
  std::cout << "address of r: " << &r << '\n';
  std::cout << "address of p: " << &p << '\n';

  // 2. Reassignment Is Not Possible With Reference
  int var = 20;
  r = var; // r is still bound to i, so i is now 20
  p = &var;
  *p = 30; // var is now 30

  // 3. NULL value
  {
    int *p = NULL;
    // int &r; // Declaration of reference variable 'r' requires an initializer
    // r = i;
  }

  // 4. Arithmetic Operations
  {
    int i = 10;
    int *p = &i;
    p++; // p is now pointing to the next memory location

    int &r = i;
    r++; // i is now 11
  }

  // 5. Indirection
  {
    int i = 10;
    int *p = &i;
    int **pp = &p;
    int ***ppp = &pp;

    int &r = i;
    int &rr = r;
    int &rrr = rr;
  }

  return 0;
}

/**
 * 1. Memory address
 * 2. Reassignment Is Not Possible With Reference
 * 3. NULL value
 * 4. Arithmetic Operations
 * 5. Indirection
 */