/*
 ============================================================================
 Name        : ctest14.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Precedence in C
 ============================================================================
 */

#include <stdio.h>
int main()
{
    int a = 10;
    if (a == a--)
        printf("TRUE 1\t");
    a = 10;
    if (a == --a)
        printf("TRUE 2\t");
}
