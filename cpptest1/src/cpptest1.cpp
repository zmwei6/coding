//============================================================================
// Name        : cpptest1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : pointer and const char* in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	char *ch = "Hello World!";
	*ch = 'h';
	cout << ch << endl;
	return 0;
}
