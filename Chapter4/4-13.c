/* Write a recursive version of the function reverse(s), which
   reverses the string s in place. */

#include <stdio.h>
#include <string.h>

void reverse(char [], int, int);

main()
{
  char s[] = "1234567890";

  reverse(s, 0, strlen(s)-1);
  printf("%s\n", s);

  return 0;
}

void reverse(char s[], int i, int j)
{
  int temp = s[i];

  if (i<j)
    reverse(s, i+1, j);
  s[j-i] = temp;
  if (i==0)
    s[j+1] = '\0';
}
    
