//============================================================================
// Name        : cpptest38.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : Casting in C++17
//============================================================================

#include <iostream>

int main() {
  char* a = const_cast<char*>("Hello");
  a[4] = '\0';
  std::cout << a;
}
