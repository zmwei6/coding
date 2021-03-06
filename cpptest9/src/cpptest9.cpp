//============================================================================
// Name        : cpptest9.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Conversion Constructor in C++
//============================================================================

#include <iostream>
using namespace std;

class A;

class B {
      public:
         B(){}

         B(const A&) //conversion constructor
         {
              cout << "called B's conversion constructor" << endl;
         }
};

class A {
      public:
         operator B() //conversion operator
         {
              cout << "called A's conversion operator" << endl;
              return B();
         }
};

int main()
{
    B b = A(); //what should be called here? apparently, A::operator B()
    return 0;
}
