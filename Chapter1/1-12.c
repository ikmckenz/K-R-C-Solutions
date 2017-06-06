/* Write a program that prints its input one word per line. */

#include <stdio.h>

main()
{
  int c;

  while ((c = getchar()) != EOF) {
    if (c != ' ')
      putchar(c);
    else
      printf("\n");
  }
}
