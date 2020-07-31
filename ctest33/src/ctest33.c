/*
 ============================================================================
 Name        : ctest33.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Reverse bits of a given 32 bits unsigned integer
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define	setbit(x)	1 << (x)
#define	getbit(x)	1 & (1 >> (x))

uint32_t reverseBits(uint32_t n) {
	uint32_t m = 0;
	int i, bit;
	for(i = 0; i < 32; i++)
	{
		bit = 1 & (n >> i);
		m |= (bit << (31 - i));
	}
	return m;
}

int main(void) {
	uint32_t inInt, outInt;
	inInt = 4294967293;
	outInt = reverseBits(inInt);
	printf("Reverse value = %u\n", outInt);
	return EXIT_SUCCESS;
}
