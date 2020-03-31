//============================================================================
// Name        : cpptest11.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : virtual function in C++
//============================================================================
/*
 * When we make a function virtual, compiler adds an extra pointer vptr to objects of the class.
 * Compiler does this to achieve run time polymorphism. The extra pointer vptr adds to the size of objects,
 * that is why we get 8 as size of Test2.
 */

#include <iostream>
using namespace std;

class Test1
{
    int x;
public:
    void show() {  }
};

class Test2
{
    int x;
public:
    virtual void show() {  }
};

int main(void)
{
    cout<<sizeof(Test1)<<endl;
    cout<<sizeof(Test2)<<endl;
    return 0;
}
