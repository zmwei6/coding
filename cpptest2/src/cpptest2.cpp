//============================================================================
// Name        : cpptest2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Static member variable in C++
//============================================================================

#include<iostream>

using namespace std;
class abc {
   public:
      static int x;
      int i;

      abc() {
         i = ++x;
      }
   };
int abc::x;

main() {
   abc m, n, p;

   cout<<m.x<<" "<<m.i<<endl;
}
