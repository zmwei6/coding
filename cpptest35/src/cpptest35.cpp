//============================================================================
// Name        : cpptest35.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : C++ TEST1 in C++17
//============================================================================
/*
 * For both a1 + a2 and a1 == a2, the built-in operators operator+ and operator== for int is used.
 * The two objects a1 and a2 are implicitly converted first to bool and then to int before calling the
 * operator. In both cases, they convert first to true, then to 1.
 * 1 + 1 equals 2, and 1 == 1 is true, so 21 is printed.
 */

#include <iostream>

struct A {
  A(int i) : m_i(i) {}
  operator bool() const { return m_i > 0; }
  int m_i;
};

int main() {
  A a1(1), a2(2);
  std::cout << a1 + a2 << (a1 == a2);
}
