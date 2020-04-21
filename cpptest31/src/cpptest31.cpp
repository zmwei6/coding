//============================================================================
// Name        : cpptest31.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : Multiple Inheritance in C++
//============================================================================
/*
 * On the second line, d2 is initialized. But why are the constructors (as opposed to the
 * copy constructors) for the base classes, called? Why do we see ABCd instead of abcd?
 * when you provide a user-defined copy constructor, this is something you have to do explicitly.
 */

#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "A"; }
    A(const A &) { cout << "a"; }
};

class B: public virtual A
{
public:
    B() { cout << "B"; }
    B(const B &) { cout<< "b"; }
};

class C: public virtual A
{
public:
    C() { cout<< "C"; }
    C(const C &) { cout << "c"; }
};

class D:B,C
{
public:
    D() { cout<< "D"; }
    D(const D &) { cout << "d"; }
};

int main()
{
    D d1;
    D d2(d1);
}
