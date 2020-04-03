/*
 ============================================================================
 Name        : ctest18.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Prefix and Postfix increment in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main(){
	int a=1;
	void xyz(int , int);
	xyz(++a,a++);		// what's difference: xyz(++a,a++) and xyz(a++,++a)
	xyz(a++,++a);
	printf("%d\n",a);
}
void xyz(int x, int y){
    printf("%d %d ",x,y);
}
