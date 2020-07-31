/*
 ============================================================================
 Name        : ctest40.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Letter Combinations of a Phone Number
 ============================================================================
 */

/* Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the
 * number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not
 * map to any letters.
*/

/*
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
	char *letters[8] = {"2abc", "3def", "4ghi", "5jkl", "6mno", "7pqrs", "8tuv", "9wxyz"};
	int lettersSize[] = {3, 3, 3, 3, 3, 4, 3, 4}, num;
	char **returnString, *letter, **p;
	int i, j, len, subreturnSize;
	len = strlen(digits);

	switch (digits[0])
	{
	case '2':
		*returnSize = lettersSize[0];
		num = 3;
		letter = letters[0] + 1;
		break;
	case '3':
		*returnSize = lettersSize[1];
		num = 3;
		letter = letters[1] + 1;
		break;
	case '4':
		*returnSize = lettersSize[2];
		num = 3;
		letter = letters[2] + 1;
		break;
	case '5':
		*returnSize = lettersSize[3];
		num = 3;
		letter = letters[3] + 1;
		break;
	case '6':
		*returnSize = lettersSize[4];
		num = 3;
		letter = letters[4] + 1;
		break;
	case '7':
		*returnSize = lettersSize[5];
		num = 4;
		letter = letters[5] + 1;
		break;
	case '8':
		*returnSize = lettersSize[6];
		num = 3;
		letter = letters[6] + 1;
		break;
	case '9':
		*returnSize = lettersSize[7];
		num = 4;
		letter = letters[7] + 1;
		break;
	default:
		break;
	}
	if(len == 1)
	{
		*returnSize = num;
		returnString = (char **)malloc((*returnSize) * sizeof(char *));

		for(i = 0; i < (*returnSize); i++)
		  returnString[i] = (char *)malloc((len + 1) * sizeof(char));
		for(i = 0; i < num; i++)
		{
			strncpy(returnString[i], letter + i, 1);
		}
		return returnString;
	}
	else
	{
		p = letterCombinations(digits + 1, &subreturnSize);
		*returnSize *= subreturnSize;
	}

	/* allocate 2D-Array */
	returnString = (char **)malloc((*returnSize) * sizeof(char *));

	for(i = 0; i < (*returnSize); i++)
	{
	  returnString[i] = (char *)malloc((len + 1) * sizeof(char));
	  memset(returnString[i], 0, len + 1);
	}

	for(i = 0; i < num; i++)
	{
		for(j = 0; j < subreturnSize; j++)
		{
			strncpy(returnString[i*subreturnSize + j], letter + i, 1);
			strcat(returnString[i*subreturnSize + j], p[j]);
		}
	}
	for(i = 0; i < subreturnSize; i++)
	  free(p[i]);
	free(p);

	return returnString;
}

int main(void) {
	char *digits = {"247"}, **p;
	int returnSize, i;

	p = letterCombinations(digits, &returnSize);
	for(i = 0; i < returnSize - 1; i++)
		printf("%s, ", p[i]);

	printf("%s\n",p[i]);
	/* free a pointer to a pointer */
	for(i = 0; i < strlen(digits); i++)
	  free(p[i]);
	free(p);

	return EXIT_SUCCESS;
}
