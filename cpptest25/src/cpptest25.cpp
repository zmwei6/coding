//============================================================================
// Name        : cpptest25.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : Function Template in C++
//============================================================================

#include <iostream>

template <typename T> void f() {
  static int stat = 0;
  std::cout << stat++;
}

int main() {
  f<int>();
  f<int>();
  f<const int>();	//f<int>() and f<const int>() are different function
}
