/* Revise the main routine of the longest-line program so it will correctly 
print the length of arbitrarily long input lines, and as much as possible 
of the text. */

/* This one was pretty tricky. I couldn't find a way to do it by only
modifying the main function, so instead I modified the getline function.
Also, I print (MAXLINE - 2) characters of text. I feel like that is good
enough for "as much as possible". */


#include <stdio.h>
#define MAXLINE 10

int getline(char line[], int maxline);
void copy(char to[], char from []);


main()
{
  int len, max;
  char line[MAXLINE], longest[MAXLINE];

  max = 0;
  while ((len = getline(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0)
    printf("The longest line was %d characters, and the first few characters were:\n%s",
	   max, longest);
  return 0;
}


int getline(char s[], int lim)
{
  int c, i, full;

  for (i=0; i<lim-2 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  full = i;
  if (c!='\n') {
    while ((c=getchar())!=EOF && c!='\n')
      ++full;
  }  
  s[i] = c;
  ++i;
  s[i] = '\0';
  return full;
}


void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from [i]) != '\0')
    ++i;
}
