//============================================================================
// Name        : cpptest6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Inheritance in C++
//============================================================================

#include<iostream>
#include<stdio.h>

using namespace std;

class Base
{
public:
  Base()
  {
    fun(); //note: fun() is virtual
  }
  virtual void fun()
  {
    cout<<"\nBase Function";
  }
};

class Derived: public Base
{
public:
  Derived(){}
  virtual void fun()
  {
    cout<<"\nDerived Function";
  }
};

int main()
{
  Base* pBase = new Derived();
  delete pBase;
  return 0;
}
