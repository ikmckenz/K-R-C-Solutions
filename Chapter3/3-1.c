/* Our binary search makes two tests inside the loop, when
one would suffice (at the price of more tests outside). 
Write a version with only one test inside the loop and
measure the difference in run-time. */

#include <stdio.h>
#define LEN 2000000

int binsearch(int x, int v[], int n);

main()
{
  int i;
  int v[LEN];

  for (i=0; i<LEN; ++i)
    v[i] = i;
  
  printf("%d\n", binsearch(1000000, v, LEN));

  return 0;
}

int binsearch(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n-1;
  while (low+1 < high) {
    mid = (low+high) / 2;
    if (x <= v[mid])
      high = mid;
    else
      low = mid + 1;
  }
  if (x == v[mid])
    return mid;
  else if (x == v[low])
    return low;
  else
    return -1;
}
