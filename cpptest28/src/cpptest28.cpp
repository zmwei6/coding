//============================================================================
// Name        : cpptest28.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : C++ TEST1 in C++
//============================================================================

/*
 * Is foo called both times or just once? The C++ standard says "A default argument is
 * evaluated each time the function is called with no argument for the corresponding parameter."
 */

#include <iostream>
using namespace std;

int foo() {
  cout << 1;
  return 1;
}

void bar(int i = foo()) {}

int main() {
  bar();
  bar();
}
