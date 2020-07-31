/*
 ============================================================================
 Name        : ctest41.c
 Author      : Zimin Wei
 Version     :
 Copyright   : Your copyright notice
 Description : Smart TV keyboard
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Smart TV keyboard


Remote: directional keys (up, down, left, right), select

Layout of our on-screen keyboard:
a  b  c  d  e  f  g  h  i
j  k  l  m  n  o  p  q  r
s  t  u  v  w  x  y  z  DONE

Our cursor is controlled by 5 input buttons: left, right, up, down, and select.
The keyboard loads with the cursor at the ‘a’ character.
The cursor can only move horizontally or vertically, not diagonally.
To finalize the input text and dismiss the keyboard, we must select the DONE key at the end.

Objective: what is the minimum number of presses on the remote does it take to input a given word?

"cat"
right, right, select => "c", 3
left, left, select => "a", 3
right, down, down, select => "t", 4  or "down, right, down"
right x7, select => DONE, 8

num_presses("cat") = 18 = 8+4+3+3

a = (0,0) // move i = 0 to i = 1 i.e. t(2,1) column. down a(0, 1) to t(2, 1)
t = (2,1)
distance = x_diff + y_diff
         = (2-0) + (1-0)
*/
// To execute C, please define "int main()"

int num_presses(char *pre_str, int strSize)
{
  char keytable[3][9] = {
      {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'},
      {'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'},
      {'s', 't', 'u', 'v', 'w', 'x', 'y', 'z', '*'}
  };

  if(!pre_str || !strSize) return -1;

  int i, j, k, diff_x = 0, diff_y = 0, coor[strlen(pre_str) * 2 + 2];
  char str[strlen(pre_str) + 1];
  strmove(str, pre_str, strlen(pre_str);
  strcat(str, "*");
  k = 0;
  num_chars = strlen(str) + 2;
  for(i = 0; i < 3; i++)
  {
    for(j = 0; j < 9; j++)
    {
      if(keytable[i][j] == *str++ && *str != '\0')
      {
        coor[k++] = i;
        coor[k++] = j;
        i = 0;
        break;
      }
    }
  }

  for(i = 2; i < num_chars; i + 2)
  {
      diff_x += abs(coor[i] - coor[ i - 2]);
      diff_y += abs(coor[i + 1] - coor[ i - 1]);
  }
  diff_x += coor[0];
  diff_y += coor[1];

  return (diff_x + diff_y);
}


int main() {
  printf("result = %d\n", num_presses("cat", 3));
  return 0;
}
