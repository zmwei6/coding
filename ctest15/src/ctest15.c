/*
 ============================================================================
 Name        : ctest15.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Loop in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
     static int i;
     int j;
     for(j=0;j<=5;j+=2)
     switch(j)
     {
        case 1: i++;break;
        case 2: i+=2;
        case 4: i%=2;j=-1;continue;
        default: --i; continue;
     }
     printf ("%d", i);
     return 0;
}
