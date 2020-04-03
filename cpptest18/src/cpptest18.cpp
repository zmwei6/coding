//============================================================================
// Name        : cpptest18.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : Class in Class in C++, Ansi-style
//============================================================================
/*
 * Member variables are initialized before the constructor is called. The destructor is called
 * before member variables are destroyed.
 */

#include <iostream>

class A {
public:
  A() { std::cout << 'a'; }
  ~A() { std::cout << 'A'; }
};

class B {
public:
  B() { std::cout << 'b'; }
  ~B() { std::cout << 'B'; }
  A a;
};

int main() { B b; }
