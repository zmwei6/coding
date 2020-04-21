//============================================================================
// Name        : cpptest34.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : C++ TEST1 in C++17
//============================================================================
/*
 * Initializer list constructors are greedy, so even though A(int) constructor is available,
 * the standard mandates that initializer_list<int> is prioritized
 */

#include <initializer_list>
#include <iostream>

struct A {
  A() { std::cout << "1"; }

  A(int) { std::cout << "2"; }

  A(std::initializer_list<int>) { std::cout << "3"; }
};

int main(int argc, char *argv[]) {
  A a1;
  A a2{};
  A a3{ 1 };
  A a4{ 1, 2 };
}
