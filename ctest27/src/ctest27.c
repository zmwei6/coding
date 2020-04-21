/*
 ============================================================================
 Name        : ctest27.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Pointers in C
 ============================================================================
 */
/*
 * Error: cannot use static for function parameters
 */

#include<stdio.h>
int *check(static int, static int);

int main()
{
    int *c;
    c = check(10, 20);
    printf("%d\n", c);
    return 0;
}
int *check(static int i, static int j)
{
    int *p, *q;
    p = &i;
    q = &j;
    if(i >= 45)
        return (p);
    else
        return (q);
}
