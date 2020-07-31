/*
 ============================================================================
 Name        : ctest32.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j, k = 0;
    int *idx;
    idx = (int *)malloc((*returnSize) * (*returnSize) * sizeof(int));
    memset(idx, 0, (*returnSize) * (*returnSize));
    for(i = 0; i < numsSize - 1; i++)
    {
        for(j = i + 1; j < numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                idx[k++] = i;
                idx[k++]= j;
                break;
            }
        }
    }
    return idx;
}

int main()
{
    int nums[] = {2, 7, 11, 15, 3, 6}, numsSize, returnSize, target;
    int *returnIdx;
    target = 9;
    numsSize = sizeof(nums)/sizeof(nums[0]);
    returnSize = 2;
    returnIdx = twoSum(nums, numsSize, target, &returnSize);
    free(returnIdx);
    return 0;
}
