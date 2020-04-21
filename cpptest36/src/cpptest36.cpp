//============================================================================
// Name        : cpptest36.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : Function Overloading in C++
//============================================================================
/*
 * According to the standard: "The type of a floating literal is double unless explicitly specified
 * by a suffix."
 */

#include <iostream>

void f(int) { std::cout << "i"; }
void f(double) { std::cout << "d"; }
void f(float) { std::cout << "f"; }

int main() {
  f(1.0);
}
