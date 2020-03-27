/*
 ============================================================================
 Name        : ctest5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Operator in C
 ============================================================================
 */

#include<stdio.h>
int main(void)
{
  int a = 1;
  int b = 0;
  b = a++ + a++;
  printf("%d %d",a,b);
  return 0;
}
