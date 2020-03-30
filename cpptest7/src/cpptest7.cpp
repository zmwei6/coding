//============================================================================
// Name        : cpptest7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Operators in C++
//============================================================================

class Test1 {
    int y;
};

class Test2 {
    int x;
    Test1 t1;
public:
    operator Test1() { return t1; }		//conversion constructor
    operator int() { return x; }		//conversion constructor
};

void fun ( int x )  { };
void fun ( Test1 t ) { };

int main() {
    Test2 t;
    fun(t);
    return 0;
}
