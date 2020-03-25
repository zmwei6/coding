/*
 ============================================================================
 Name        : ctest1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Operators in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i = 2, j = 3, l;
	l = i || j;
	printf("l=%d\n", l);
	return EXIT_SUCCESS;
}
