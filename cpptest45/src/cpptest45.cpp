//============================================================================
// Name        : cpptest45.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : C++ Test2 in C++ 17
//============================================================================

#include <iostream>

class C {
public:
  C(int i) : i(i) { std::cout << i; }
  ~C() { std::cout << i + 5; }

private:
  int i;
};

int main() {
  const C &c = C(1);
  C(2);
  C(3);
}
