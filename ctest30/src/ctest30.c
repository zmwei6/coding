/*
 ============================================================================
 Name        : ctest30.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Pointers in C
 ============================================================================
 */

#include<stdio.h>

int main()
{
    char str1[] = "Canada";
    char str2[] = "BIX";
    char *s1 = str1, *s2=str2;
    while(*s1++ = *s2++)
        printf("%s", str1);

    printf("\n");
    return 0;
}
