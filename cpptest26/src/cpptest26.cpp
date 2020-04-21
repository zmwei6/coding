//============================================================================
// Name        : cpptest26.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : C++ TEST1 in C++
//============================================================================

#include<iostream>

void f(int& a, const int& b) {
  std::cout << b;
  a = 1;
  std::cout << b;
}

int main(){
  int x = 0;
  f(x,x);
}
