/*
 ============================================================================
 Name        : ctest7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Operator and associativity in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int top=0;
int fun1()
{
    char a[]= {'a','b','c','(','d'};
    return a[top++];
}
int main()
{
    char b[10];
    char ch2;
    int i = 0;
    while (ch2 = fun1() != '(')
    {
        b[i++] = ch2;
    }
    printf("%s",b);
    return 0;
}
