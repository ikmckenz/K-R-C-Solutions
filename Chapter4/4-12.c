/* Adapt the ideas of printd to write a recursive version of itoa;
   that is, convert an integer into a string by calling a recursive
   routine. */

#include <stdio.h>
#define MAX 100

void itoa(char [], int);

main()
{
  char s[MAX];

  itoa(s, -12345);

  printf("The string is %s\n", s);

  return 0;
}

void itoa(char s[], int n)
{
  static i;
  
  if (n<0) {
    s[i++] = '-';
    n = -n;
  }
  if (n/10)
    itoa(s, n/10);
  s[i++] = (n%10 +'0');
  if (!(n/10))
    s[i] = '\0';
}
