/*
 ============================================================================
 Name        : ctest17.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Global and local variable in C
 ============================================================================
 */

int x;
int modifyvalue()
{
    return(x+=10);
}
int changevalue(int x)
{
    return(x+=1);
}
void main()
{
    int x=10;
    x++;
    changevalue(x);
    x++;
    modifyvalue();
    printf("First output:%d,",x);
    x++;
    changevalue(x);
    printf("Second output:%d,",x);
    modifyvalue();
    printf("Third output:%d\n",x);
}
