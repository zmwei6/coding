//============================================================================
// Name        : cpptest5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Multiple Inheritance in C++
//============================================================================

/* Since b1 and b2 both inherit from class base, two copies of class base are there in class derived.
 * This kind of inheritance without virtual causes wastage of space and ambiguities.
 * virtual base classes are used to save space and avoid ambiguities in such cases.
 */

#include<iostream>
using namespace std;

class base {
    int arr[10];
};

class b1: public base { };

class b2: public base { };

class derived: public b1, public b2 {};

int main(void)
{
	int n = sizeof(0)["abcdefghij"];
	std::cout << n << endl;
  cout<<sizeof(derived)<<endl;
  return 0;
}
