/*
 ============================================================================
 Name        : ctest25.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Increment and Macro in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define PRODUCT(x) (x*x*x*x)
int main()
{
	int x = 2;
	int result = PRODUCT(x++);
	printf("%d %d", x, result);
	return 0;
}
