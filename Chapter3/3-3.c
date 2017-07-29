/* Write a function expand(s1,s2) that expands shorthand notations
like a-z in the string s1 into the equivalent complete list 
abc...xyz in s2. Allow for letters of either case and digits, and 
be prepared to handle cases like a-b-c and a-z0-9 and -a-z. 
Arrange that a leading or trailing - is taken literally. */

/* I think this solves the problem, but I don't know what is 
meant by "Arrange that a leading or trailing - is taken 
literally", and I'm assuming that the correct way to 
handle a-b-c is first to print a-b (ab), then to print
b-c (bc), resulting in abbc. If this isn't what the author
intended then it gets more complicated. */

#include <ctype.h>
#include <stdio.h>

void expand(char s1[], char s2[]);

main()
{
  char s1[] = "a-z0-9";
  char s2[100];
	 
  expand(s1,s2);
  printf("%s\n",s2);

  return 0;
}

void expand(char s1[], char s2[])
{
  int i, j, k;

  for (i=j=0; s1[i]!='\0'; ++i) 
    if (isalnum(s1[i]) && s1[i+1]=='-' && isalnum(s1[i+2]))
      for (k=0; k<=(s1[i+2] - s1[i]); ++j, ++k)
	s2[j] = s1[i] + k;
  s2[j] = '\0';
}
