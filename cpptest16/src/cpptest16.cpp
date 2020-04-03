//============================================================================
// Name        : cpptest16.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Determines the order of member variable initialization in C++
//============================================================================
/*
 * The order in which members are initialized, including base class initialization, is determined
 * by the declaration order of the class member variables or the base class specifier list.
 */

#include <iostream>
using namespace std;

struct A {
  A() { std::cout << "A"; }
};
struct B {
  B() { std::cout << "B"; }
};

class C {
public:
  C() : a(), b() {}

private:
  B b;
  A a;
};

int main()
{
    C();
}
