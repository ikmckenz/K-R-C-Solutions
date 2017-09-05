/* Define a macro swap(t,x,y) that interchanges two arguments of 
   type t. (Block structure will help.) */

#include <stdio.h>

#define swap(t,x,y) {t temp=x; x=y; y=temp;}

main()
{
  int x, y;
  
  x = 1.0;
  y = 2.0;
  printf("x = %d, y = %d\nSwapping...\n", x, y);
  swap(int, x, y);
  printf("x = %d, y = %d\n", x, y);
  return 0;
}
