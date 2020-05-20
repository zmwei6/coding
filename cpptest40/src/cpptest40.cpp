//============================================================================
// Name        : cpptest40.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : Initialization List in C++
//============================================================================
/*
 * derived class initialization order: base class constructor, then derived class initialization list,
 * then derived constructor
 */

#include <iostream>

class A
{
public:
	A(int n = 0)
		: m_i(n)
	{
		std::cout << m_i;
	}

protected:
	int m_i;
};

class B
	: public A
{
public:
	B(int n = 5) : m_a(new A[2]), m_x(++m_i) { std::cout << m_i; }

	~B() { delete [] m_a;}

private:
	A m_x;
	A *m_a;
};

int main() {
	B b;
	std::cout << std::endl;

	return 0;
}
