/*
 ============================================================================
 Name        : ctest16.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Advanced topic in C
 ============================================================================
 */

#include "stdio.h"
extern int a=5;
main(){
	void fun();
	printf("\n a=%d",a);
	fun();
	return 0;
}
int a;
void fun(){
	printf("\n in fun a=%d",a,a++);
}
