//============================================================================
// Name        : cpptest14.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using std::cout;
class main
{
public:
   main()  { cout << "ctor is called\n";}
   ~main() { cout << "dtor is called\n";}
};
int main()
{
   class main m;
}
