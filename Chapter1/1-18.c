/* Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines. */


#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void trailing(char newline[], char line[], int len);


main()
{
  int len, i, blanks;
  char line[MAXLINE], newline[MAXLINE];

  while ((len = getline(line, MAXLINE)) > 0)
    if (len > 1) {
      trailing(newline, line, len);
      printf("%s", newline);
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


void trailing(char to[], char from[], int len)
{
  int i, blanks, test;

  test = 0;
  blanks = 0;
  for (i = len-2; i>=0, test == 0; --i)
    if (from[i] == ' ' || from[i] == '\t')
      ++blanks;
    else
      ++test;

  for (i = 0; i <= len-blanks-2; ++i)
    to[i] = from [i];
  to[i] = '\n';
  ++i;
  to[i] = '\0';
}
