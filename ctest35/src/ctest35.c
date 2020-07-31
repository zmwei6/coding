/*
 ============================================================================
 Name        : ctest35.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/* print the following pattern
 *                 *
 *                ***
 *               *****
 *              *******
 *              :
 *              :
 *            ***********
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printPattern(int N)
{
	int i, j;
	int num_space, num_str;
	char print_str[2 * N + 2];
	num_space = N  + 1;
	num_str = 2 * N + 2;
	for(i = 0; i < N; i++)
	{
		memset(print_str, 0, num_str);
		memset(print_str, 0x20, num_space - i);
		memset(&print_str[num_space - i], '*', 2 * i + 1);
		printf("%s\n", print_str);

	}
}

int main(void) {
	int rows;
	printf("Enter the rows of pattern: ");
	scanf("%d", &rows);
	printf("\nThe pattern is printed below: \n\n");
	printPattern(rows);
	return EXIT_SUCCESS;
}
