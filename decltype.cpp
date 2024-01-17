// 问题: decltype有什么用?
// 回答: decltype可以用来获取表达式的类型

#include <iostream>

template <typename T1, typename T2> auto add(T1 x, T2 y) -> decltype(x + y) {
  return x + y;
}

int main() {
  auto a = 1;
  auto b = 2.3;
  auto c = add(a, b);
  std::cout << c << std::endl;
  return 0;
}