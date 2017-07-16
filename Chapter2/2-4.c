/* Write an alternate version of squeeze(s1,s2) that deletes each
character in s1 that matches any character in the string s2. */

#include <stdio.h>

#define MAXLINE 1000

void squeeze(char str1[], char str2[], char new[]);

main()
{
  int c;
  char str1[] = "Hello, world!";
  char str2[] = "Nope!";
  char new[MAXLINE];

  squeeze(str1, str2, new);
  
  printf("%s", new);
  putchar('\n');
  return 0;
}

void squeeze(char str1[], char str2[], char new[])
{
  int i, j, place, test;

  place = 0;
  for (i=0; str1[i]!='\0'; ++i) {
    test = 0;
    for (j=0; str2[j]!='\0'; ++j)
      if (str1[i]==str2[j])
	++test;
    if (test==0)
      new[place++] = str1[i];
  }
  new[place] = '\0';
}
