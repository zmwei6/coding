/*
 ============================================================================
 Name        : ctest29.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Pointer Operator in C
 ============================================================================
 */

#include<stdio.h>

int main()
{
    int arr[2][2][2] = {10, 2, 3, 4, 5, 6, 7, 8};
    int *p, *q;
    p = &arr[1][1][1];
    q = (int*) arr;
    printf("%d, %d\n", *p, *q);
    return 0;
}
