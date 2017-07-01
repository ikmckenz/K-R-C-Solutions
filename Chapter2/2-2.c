/* Write a loop equivelant to the for loop above without using && or || */

/* The for loop they are talking about is:
for (i=0; i<lim && (c=getchar()) != '\n' && c != EOF; ++i)
  s[i] = c;  */

#include <stdio.h>

main()
{
  int i, lim, c;
  lim = 100;
  char s[lim];

  for (i=0; (i<lim) + ((c=getchar()) != '\n') + (c!=EOF) == 3; ++i)
    s[i] = c;
  
  s[i] = '\n';
  ++i;
  s[i] = '\0';

  printf("%s", s);

  return 0;
}

/* There are lots of different ways of doing this.
 I haven't seen this method yet, and it seems to work. */
