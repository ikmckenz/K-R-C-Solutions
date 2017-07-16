/* Write the function any(s1,s2), which returns the first location in 
the string s1 where any character from the string s2 occurs, or -1 if
s1 contains no characters from s2. (The standard library function
strpbrk does the same job buy returns a pointer to the location.) */

#include <stdio.h>

int any(char s1[], char s2[]);

main()
{
  char s1[] = "First string.";
  char s2[] = "Second string.";

  printf("%d\n", any(s1,s2));

  return 0;
}


int any(char s1[], char s2[])
{
  int i, j, count, test;

  count = test = 0;
  for (i=0; s1[i]!='\0' && test==0; ++i) {
    ++count;
    for (j=0; s2[j]!='\0'; ++j)
      if (s1[i]==s2[j])
	++test;
  }
  if (test==0)
    count = -1;
  
  return count;
}
