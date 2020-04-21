//============================================================================
// Name        : cpptest33.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : Function Template in C++
//============================================================================

#include <iostream>

template<class T>
void f(T) { std::cout << 1; }

template<>
void f<>(int*) { std::cout << 2; }

template<class T>
void f(T*) { std::cout << 3; }

int main() {
    int *p = NULL;
    f( p );
}
