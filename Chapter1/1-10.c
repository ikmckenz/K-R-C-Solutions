/* Write a program to copy its input to its output,
replacing each tab by \t, each backspace by \b, and each 
backslash by \\. This makes tabs and backspaces visible in an
unambiguous way. */

#include <stdio.h>

main()
{
  int c, i;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      putchar('\\');
      putchar('t');
    }
    else if (c == '\b') {
      putchar('\\');
      putchar('b');
    }
    else if (c == '\\') {
      putchar('\\');
      putchar('\\');
    }
    else
      putchar(c);
  }
}

/* I couldn't find a way to test the backspace character,
but it should work as the others do. */
