/*
 ============================================================================
 Name        : ctest28.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Pointer operator precedence in C
 ============================================================================
 */

#include<stdio.h>

int main()
{
    void *vp;
    char ch=74, *cp="JACK";
    int j=65;
    vp=&ch;
    printf("%c", *(char*)vp);
    vp=&j;
    printf("%c", *(int*)vp);
    vp=cp;
    printf("%s", (char*)vp+2);
    return 0;
}
