/*
 ============================================================================
 Name        : ctest36.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or
 * more than two continuous 'L' (late).
 * You need to return whether the student could be rewarded according to his attendance record.
 */

#include <stdio.h>
#include <stdlib.h>

int checkRecord(char * s){
    int numA = 0, numL = 0, k = 0;
    while(s[k] != '\0')
    {
    	switch (s[k])
		{
    	case 'A':
            if(1 < ++numA)
            	return 0;
		break;
    	case 'L':
    		/* first 'L' comes up */
    		if(numL == 0)
    			++numL;
    		else if('L' == s[k - 1])
			{
				if(2 < ++numL)
					return 0;
			}
			else
				numL = 1;	// not continuous of in a row of 3 'L'
		break;
    	default:
		break;
		}
        k++;
    }
    return (numA < 2 && numL < 3);
}

int main(void) {
	int r;
	char record1[] = "PPALLPLL", record2[] = "PPALLLPP", record3[] = "LALLPLLP";
	r = checkRecord(record1);
	printf("%s ---> %d\n", record1, r);
	r = checkRecord(record2);
	printf("%s ---> %d\n", record2, r);
	r = checkRecord(record3);
	printf("%s ---> %d\n", record3, r);
	return EXIT_SUCCESS;
}
