//============================================================================
// Name        : cpptest15.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Operator Precedence in C++
//============================================================================

#include<iostream>
using namespace std;
int main()
{
    int x = 1 , y = 1, z = 1;

    cout << ( ++x || ++y && ++z ) << endl;	// ( ++x || ++y && ++z ) == ( ++x || (++y && ++z) )

    cout << x << " " << y << " " << z ;

    return 0;
}
