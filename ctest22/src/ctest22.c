/*
 ============================================================================
 Name        : ctest22.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Nested loop in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main(){
	int i;
	for(i=1;i++<=1;i++)
	for(i++;i++<=6;i++)
	i++;
	printf("%d",i);
}
