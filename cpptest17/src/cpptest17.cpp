//============================================================================
// Name        : cpptest17.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 * in character arithmetic, typecasting of char variable to ‘char’ is explicit and
 * to ‘int’ it is implicit
 */

#include <iostream>
using namespace std;

void f(unsigned int) { std::cout << "u"; }
void f(int)          { std::cout << "i"; }
void f(char)         { std::cout << "c"; }

int main() {
    char x = 1;
    char y = 2;
    f(x + y);
}
