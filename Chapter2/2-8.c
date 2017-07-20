/* Write a function rightrot(x,n) that returns the value of the
integer x rotated to the right by n bit positions. */

#include <stdio.h>

int rightrot(int x, int n);


main()
{
  printf("%d\n", rightrot(138, 1));

  return 0;
}


int rightrot(int x, int n)
{
  while (n > 0) {
    if (x&1 == 0)
      x = x >> 1;
    else
      x = (x >> 1) | ~(~0 >> 1);
    --n;
  }
  return x;
}
