/* Write the function itob(n,s,b) that converts the integer n
into a base b character representation in the string s. In
particular, itob(n,s,16) formats n as a hexadecimal integer
in s. */

#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

main()
{
  char s[100];

  itob(105,s,16);

  printf("%s\n", s);

  return 0;
}


void itob(int n, char s[], int b)
{
  int i, new, remainder;

  i = 0;
  new = n;
  do {
    remainder = new % b;
    if (remainder >=10)
      remainder = remainder - 10 + 'a';
    else
      remainder = remainder + '0';
    s[i] = remainder;
    new = new/b;
    ++i;
  }
  while (new != 0);
  s[i] = '\0';
  
  reverse(s);
}

void reverse(char s[])
{
  int c, i, j;

  for (i=0, j=strlen(s)-1; i<j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
