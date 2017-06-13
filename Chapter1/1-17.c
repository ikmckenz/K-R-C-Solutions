/* Write a program to print all input lines that are longer than 80 characters. */

#include <stdio.h>
#define MAXLINE 1000
#define THRESH 80

int getline(char line[], int maxline);
void copy(char to[], char from []);


main()
{
  int len, max;
  char line[MAXLINE], longest[MAXLINE];

  max = 0;
  while ((len = getline(line, MAXLINE)) > 0)
    if (len > THRESH) {
      printf("%s", line);
    }
  return 0;
}


int getline(char s[], int lim)
{
  int c, i;

  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

