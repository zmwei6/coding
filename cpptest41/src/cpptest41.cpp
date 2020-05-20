//============================================================================
// Name        : cpptest41.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : Const objects in C++
//============================================================================

#include <iostream>

class A
{
public:
	A() {}

public:
	virtual void f(int n) { std::cout << n << 1;}
	virtual ~A() { }

	void f(int n) const { std::cout << n; }
};

class B
	: public A
{
public:
	void f(int n) { std::cout << (n << 1);}

	void f(int n) const { std::cout << n + 1; }
};

int main() {
	const A a;
	B b;
	A &c = b;
	const A *d = &b;

	a.f(2);
	b.f(2);
	c.f(1);
	d->f(1);

	std::cout << std::endl;

	return 0;
}
