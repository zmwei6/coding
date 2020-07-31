/*
 ============================================================================
 Name        : ctest34.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
   The robot can only move either down or right at any point in time. The robot is trying to reach the
   bottom-right corner of the grid (marked 'Finish' in the diagram below).
   How many possible unique paths are there?
*/

#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int m, int n){
    int i, j, path1, path2, path;
    if(m == 1 || n == 1)
    	return 1;
    if(m == 2)
    	return n;
    if(n == 2)
    	return m;
    path1 = 0;
    for(i = 1; i < n; i++)
    	path1 += uniquePaths(m-1, n-i);
    path2 = 0;
    for(j = 1; j < m; j++)
    	path2 += uniquePaths(m-j, n-1);
    path = path1 + path2;
    return path;
}

int main(void) {
	int paths;
	paths = uniquePaths(4, 4);
	printf("paths = %d\n", paths);
	return EXIT_SUCCESS;
}
