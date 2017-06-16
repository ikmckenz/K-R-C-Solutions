/* Write a program detab that replaces tabs in the input with the proper
number of blanks to space to the next tab stop. Assume a fixed set of 
tab stops, say every n columns. Should n be a variable or a symbolic parameter? */

#include <stdio.h>

#define TABWIDTH 4

main()
{
  int c, i;

  while ((c=getchar())!=EOF) {
    if (c == '\t')
      for(i=0; i<TABWIDTH; ++i)
	putchar(' ');
    else
      putchar(c);
  }
  return 0;
}

/* I feel like this solution is too simple, what am I missing? */
