/* In a two's complement number representation, our version 
of itoa does not handle the largest negative number, that is,
the value of n equal to -(2^(wordsize-1)). Explain why not.
Modify it to print that value correctly, regardless of the
machine on which it runs. */

#include <stdio.h>
#include <limits.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

main()
{
  char s[100];
  int n;
  
  n = INT_MIN;
  itoa(n,s);
  
  printf("%s\n", s);

  return 0;
}

void itoa(int n, char s[])
{
  int i, original;
  original = n;

  i = 0;
  if (original < 0) {
    do {
      s[i++] = abs(n % 10) + '0';
    } while (n /= 10);
    s[i++] = '-';
  }
  else
    do {
      s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[])
{
  int length = strlen(s);
  int c, i, j;

  for (i = 0, j = length - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
