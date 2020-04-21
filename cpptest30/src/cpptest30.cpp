//============================================================================
// Name        : cpptest30.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : Function Template in C++
//============================================================================

#include <iostream>

template <class T> void f(T &i) { std::cout << 1; }

template <> void f(const int &i) { std::cout << 2; }

int main() {
  int i = 42;
  f(i);
}
