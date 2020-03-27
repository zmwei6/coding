/*
 ============================================================================
 Name        : ctest8.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Storage Class and Loop in C
 ============================================================================
 */

#include <stdio.h>
int fun()
{
  static int num = 16;
  return num--;
}

int main()
{
  for(fun(); fun(); fun())
    printf("%d ", fun());
  return 0;
}
