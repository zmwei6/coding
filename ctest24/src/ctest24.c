/*
 ============================================================================
 Name        : ctest24.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Increment and Logical OR in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,b,c;
	a = b = c = 10;
	c = a++ || ++b && ++c;
	printf("%d %d %d",c, a, b);
	return 0;
}
