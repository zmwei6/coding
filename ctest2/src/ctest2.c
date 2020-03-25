/*
 ============================================================================
 Name        : ctest2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Pointer and Array in C
 ============================================================================
 */

/* Let us consider the expression ++*p in first printf(). Since precedence of prefix ++ and * is same,
 * associativity comes into picture. *p is evaluated first because both prefix ++ and * are right to left
 * associative. When we increment *p by 1, it starts pointing to second character of “knowledge”.
 * Therefore, the first printf statement prints “nowledge”. Let us consider the expression *p++ in second
 * printf() . Since precedence of postfix ++ is higher than *, p++ is evaluated first. And since it’s a
 * psotfix ++, old value of p is used in this expression. Therefore, second printf statement prints “nowledge”.
 * In third printf statement, the new value of p (updated by second printf) is used, and third printf()
 * prints “s”.
 */

#include<stdio.h>
int main()
{
  char *s[] = { "knowledge","is","power"};
  char **p;
  p = s;
  printf("%s ", ++*p);
  printf("%s ", *p++);
  printf("%s ", ++*p);

  return 0;
}
