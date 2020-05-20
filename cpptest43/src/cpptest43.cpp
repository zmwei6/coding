//============================================================================
// Name        : cpptest43.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : C++ TEST2 in C++17
//============================================================================

#include <iostream>

struct X {
  X() { std::cout << "a"; }
  X(const X &x) { std::cout << "b"; }
  const X &operator=(const X &x) {
    std::cout << "c";
    return *this;
  }
};

int main() {
  X x;
  X y(x);
  X z = y;
  z = x;
}
