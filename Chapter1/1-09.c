/* Write a program to copy its input to its output,
replacing each string of one or more blanks by a single blank */

#include <stdio.h>

main()
{
  int c, track;

  track = 0;
  while ((c = getchar()) != EOF) {
    if (track == 0) {
      putchar(c);
      if (c == ' ')
	++track;
    }
    else
      if (c != ' ') {
	putchar(c);
	track = 0;
      }
  }
}
