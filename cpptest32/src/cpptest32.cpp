//============================================================================
// Name        : cpptest32.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : C++ TEST1 in C++
//============================================================================
/*
 *  The expression new A is not evaluated, and A is never constructed.
 *  The expression is only used for sizeof.
 */

#include <iostream>

struct A {
    A() { std::cout << "A"; }
    ~A() { std::cout << "a"; }
};

int main() {
    std::cout << "main";
    return sizeof new A;
}
