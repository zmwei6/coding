//============================================================================
// Name        : cpptest23.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : C++ TEST1 in C++
//============================================================================

#include <iostream>

class A
{
public:
	A(int n = 0)
		: m_n(0)
	{
		std::cout << 'd';
	}

	A(const A& a)
		: m_n(a.m_n)
	{
		std::cout << 'c';
	}

private:
	int m_n;
};

void f(const A &a1, const A &a2 = A())
{
}

int main() {
	A a(2), b;
	const A c(a), &d = b, e = b;
	b = d;
	A *p = new A(c), *q = &a;
	static_cast<void>(q);
	delete p;
	f(3);
	std::cout << std::endl;

	return 0;
}
