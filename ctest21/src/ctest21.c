/*
 ============================================================================
 Name        : ctest21.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : do-while loop in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main(){
	int a;
	a=10;
	do
	while(a++<10);
	while(a++<=11);
	printf("%d",a);
}
