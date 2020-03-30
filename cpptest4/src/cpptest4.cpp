//============================================================================
// Name        : cpptest4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Coversion Constructor in C++
//============================================================================

#include<iostream>
using namespace std;

class A {
 public:
    A(int ii = 0) : i(ii) {}
    void show() { cout << "i = " << i << endl;}
 private:
    int i;
};

class B {
 public:
    B(int xx) : x(xx) {}
    operator A() const { return A(x); }
 private:
    int x;
};

void g(A a)
{  a.show(); }

int main() {
  B b(10);
  g(b);
  g(20);
  return 0;
}
