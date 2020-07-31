/*
 ============================================================================
 Name        : ctest39.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of
 * the stock), design an algorithm to find the maximum profit.
 * Note that you cannot sell a stock before you buy one.
 */

#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize){
    int max = 0, diff, i, j;
    if(!prices || !pricesSize) return 0;
    diff = 0;
    for(i = 0; i < pricesSize - 1; i++)
    {
		for(j = i + 1; j < pricesSize; j++)
		{
			diff = prices[j] - prices[i];
			if(diff > max)
			{
				max = diff;
			}
		}
    }
    return max;
}

int main(void) {
	int prices[] = {2,1,2,1,0,1,2}, profit;
	profit = maxProfit(prices, sizeof(prices)/sizeof(prices[0]));
	printf("Max profit = %d\n", profit);
	return EXIT_SUCCESS;
}
