/*
 ============================================================================
 Name        : ctest12.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * When %s is used to print a string, printf starts from the first character at given address and keeps
 * printing characters until it sees a string termination character '\0'. When a character array is initialized
 * with a double quoted string and array size is not specified, compiler automatically allocates one extra
 * space for string terminator ‘\0'.
 */

#include<stdio.h>

int main()
{
  char arr[] = "geeks\0 for geeks";
  char *str = "geeks\0 for geeks";
  printf ("arr = %s, sizeof(arr) = %d \n", arr, sizeof(arr));
  printf ("str = %s, sizeof(str) = %d", str, sizeof(str));
  return 0;
}
