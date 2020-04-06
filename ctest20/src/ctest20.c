/*
 ============================================================================
 Name        : ctest20.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Increment in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main(){
	int a,b;
	a=b=1;
	a=a++ + ++b;
	b=b++ + ++a;
	printf("%d%d",a,b);
}
