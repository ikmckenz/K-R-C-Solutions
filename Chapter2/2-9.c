/* In a two's complement number system, x&=(x-1) deletes the
rightmost 1-bit in x. Explain why. Use this observation to
write a faster version of bitcount. */

#include <stdio.h>

int bitcount(unsigned x);


main()
{
  printf("%d\n", bitcount(32));

  return 0;
}


int bitcount(unsigned x)
{
  int b;

  for (b=0; x!=0; ++b)
    x &= (x-1);

  return b;
}
