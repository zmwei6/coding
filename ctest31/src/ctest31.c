/*
 ============================================================================
 Name        : ctest31.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Pointer operator in C
 ============================================================================
 */

#include<stdio.h>
#include<string.h>

int main()
{
    int i, n;
    char *x="Alice";
    n = strlen(x);
    *x = x[n];
    for(i=0; i<=n; i++)
    {
        printf("%s ", x);
        x++;
    }
    printf("\n", x);
    return 0;
}
