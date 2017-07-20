/* Write a function invert(x,p,n) that returns x with the n bits
that begin at position p inverted (i.e., 1 changed into 0 and 
vice versa), leaving the others unchanged. */

#include <stdio.h>

int invert(int x, int p, int n);


main()
{
  printf("%d\n", invert(85, 4, 1));

  return 0;
}


int invert(int x, int p, int n)
{
  return x ^ (~(~0 << n) << (p+1-n));
}
