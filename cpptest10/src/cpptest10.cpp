//============================================================================
// Name        : cpptest10.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Conversion Constructor in C++
//============================================================================

#include <iostream>
using namespace std;

class ClassB;

class ClassA
{
    public:
    ClassA( const int& num )
    : _number( num )
    { cout << "ClassA int constructor\n"; }

    private:
    int _number;
};

class ClassB
{
    public:
    ClassB( const int& num )
    : _number( num )
    { cout << "ClassB int constructor\n"; }

    operator ClassA() const throw()
    {
        cout << "ClassB operator ClassA()\n";
        return ClassA( _number );
    }
    operator int() const throw()
    {
        cout << "ClassB operator int()\n";
        return _number;
    }

    private:
    int _number;
};

int main( int argc, const char* argv[] )
{
    cout << "Creating b:\n";
    ClassB b( 5 );
    cout << "Converting b to a ClassA:\n";
    ClassA a = b;
    ClassA c = ClassB(10);
    ClassA d = b.operator ClassA();
    ClassA e = static_cast<ClassA>( b );
}
