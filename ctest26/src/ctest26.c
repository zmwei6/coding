/*
 ============================================================================
 Name        : ctest26.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Pointers in C
 ============================================================================
 */

#include<stdio.h>

int main()
{
    static char *s[] = {"black", "white", "pink", "violet"};
    char **ptr[] = {s+3, s+2, s+1, s}, ***p;
    p = ptr;
    ++p;
    printf("%s", **p+1);
    return 0;
}
