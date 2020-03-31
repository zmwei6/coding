/*
 ============================================================================
 Name        : ctest9.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Pointer and Array in C
 ============================================================================
 */

#include <stdio.h>
#define R 4
#define C 4

void modifyMatrix(int mat[][C])
{
   mat++;
   mat[1][1] = 100;
   mat++;
   mat[1][1] = 200;
}

void printMatrix(int mat[][C])
{
    int i, j;
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
            printf("%3d ", mat[i][j]);
        printf("\n");
    }
}

int main()
{
    int mat[R][C] = { {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    printf("Original Matrix \n");
    printMatrix(mat);

    modifyMatrix(mat);

    printf("Matrix after modification \n");
    printMatrix(mat);

    return 0;
}
