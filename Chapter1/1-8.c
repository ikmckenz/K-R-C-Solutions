/* Write a program to count blanks, tabs, and newlines. */

#include <stdio.h>

main()
{
  int c;
  int blank, tab, nl;

  blank = tab = nl = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n')
      ++nl;
    if (c == '\t')
      ++tab;
    if (c == ' ')
      ++blank;
  }
  printf("There are %d blanks, %d tabs, and %d newlines.\n", blank, tab, nl);
}
