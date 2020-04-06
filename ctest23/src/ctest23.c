/*
 ============================================================================
 Name        : ctest23.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Post Increment in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main(){
	int i;
	i=1;
	i=i+2*i++;
	printf("%d",i);
}
