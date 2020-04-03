/*
 ============================================================================
 Name        : ctest13.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : bit fields in C
 ============================================================================
 */

int main(void)
{
    struct str
    {
        int i: 1;
        int j: 2;
        int k: 3;
        int l: 4;
    };

    struct str s;

    s.i = 1;
    s.j = 2;
    s.k = 5;
    s.l = 10;

    printf(" i: %d \n j: %d \n k: %d \n l: %d \n", s.i, s.j, s.k, s.l);

    return 0;
}
