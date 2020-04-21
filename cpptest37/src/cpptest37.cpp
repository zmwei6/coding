//============================================================================
// Name        : cpptest37.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : C++ TEST1 in C++17
//============================================================================
/*
 * To fix the problem, change Y y(X()) to either Y y{X{}} (modern C++)
 */

#include <iostream>

struct X {
  X() { std::cout << "X"; }
};

struct Y {
  Y(const X &x) { std::cout << "Y"; }
  void f() { std::cout << "f"; }
};

int main() {
  Y y(X());
  y.f();
}
