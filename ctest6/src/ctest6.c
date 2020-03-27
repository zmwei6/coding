/*
 ============================================================================
 Name        : ctest6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Operator and associativity in C
 ============================================================================
 */

#include <stdio.h>
int main()
{
   int y = 0;
   int x = (~y == 1);
   printf("%d", x);
   return 0;
}
