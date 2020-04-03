/*
 ============================================================================
 Name        : ctest19.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Point and increment in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void xyz(int p1, int *p2){
	++p1;
	++*p2;
	printf("%d%d",p1,*p2);
}
void main(){
	int a=10;
	xyz(a++,++*(&a));
	xyz(a++,++*(&a));
	printf("%d",a);
}
