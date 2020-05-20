//============================================================================
// Name        : cpptest44.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : C++ TEST2 in C++
//============================================================================
/*
 * A string literal is not a std::string, but a const char[]
 */

#include <iostream>
#include <string>

void f(const std::string &) { std::cout << 1; }

void f(const void *) { std::cout << 2; }

int main() {
  f("foo");
  const char *bar = "bar";
  f(bar);
}
