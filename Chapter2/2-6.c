/* Write a function setbits(x,p,n,y) that returns x with the n bits
that begin at position p set to the rightmost n bits of y, leaving
other bits unchanged. */

#include <stdio.h>

int setbits(int x, int p, int n, int y);


main()
{ 
  printf("%d\n", setbits(71, 1, 2, 5));

  return 0;
}


int setbits(int x, int p, int n, int y)
{
  /* (mask off the n rightmost digits of y and move them p+1-n spots to the left)
     or 
     (remove n digits from x starting at p and replace them with zeros) */
  return ((y & ~(~0 << n)) << p+1-n) | ((x & ~(~(~0 << n) << p+1-n)));
}
