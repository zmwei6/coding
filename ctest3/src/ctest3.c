/*
 ============================================================================
 Name        : ctest3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Operator and Array in C
 ============================================================================
 */

#include <stdio.h>
#define VAL 32

int main()
{
    char arr[] = "geeksquiz";
    *(arr + 0) &= ~VAL;
    *(arr + 5) &= ~VAL;
    printf("%s", arr);

    return 0;
}
