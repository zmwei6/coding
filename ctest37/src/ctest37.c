/*
 ============================================================================
 Name        : ctest37.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void minHead(int * subheights, int size)
{
	int i, min;
	for(i = 1; i < size; i++)
	{
		if(subheights[i] < subheights[0])
		{
			min = subheights[i];
			subheights[i] = subheights[0];
			subheights[0] = min;
		}
	}
}

int heightChecker(int* heights, int heightsSize){
	int i, j, min, diff;
	int pre_heights[heightsSize];
	memmove(pre_heights, heights, heightsSize * sizeof(int));
	for(i = 0; i < heightsSize - 1; i++)
	{
		for(j = i + 1; j < heightsSize; j++)
		{
			if(heights[j] < heights[i])
			{
				min = heights[j];
				heights[j] = heights[i];
				heights[i] = min;
			}
		}
	}
	diff = 0;
	for(i = 0; i < heightsSize; i++)
		if(heights[i] != pre_heights[i])
			diff++;
	printf("Minimal = %d\n", diff);
	return diff;
}

int main(void) {
	int i, heights[] = {1,1,4,2,1,3}, heightsSize;
	heightsSize = sizeof(heights)/sizeof(heights[0]);
	heightChecker(heights, heightsSize);
	printf("Target[] = {");
	for(i = 0; i < heightsSize - 1; i++)
		printf("%d, ", heights[i]);
	printf("%d}\n", heights[i]);
	return EXIT_SUCCESS;
}
