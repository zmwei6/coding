//============================================================================
// Name        : cpptest24.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : Pure virtual function in C++
//============================================================================

#include <iostream>

struct Base {
    virtual int f() = 0;
};

int Base::f() { return 1; }

struct Derived : Base {
    int f() override;
};

int Derived::f() { return 2; }

int main() {
    Derived object;
    std::cout << object.f();
    std::cout << ((Base&)object).f();	//((Base&)object).f() casts object to a Base& before calling f(), but since f() is a virtual function, Derived::f() is still called, returning 2.
}
