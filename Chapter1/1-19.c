/* Write a function reverse(s) that reverses the character string s.
Use it to write a program that reverses its input a line at a time. */

#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void reverse(char to[], char from[], int len);

main()
{
  int len;
  char reversed[MAXLINE], line[MAXLINE];

  while ((len = getline(line, MAXLINE)) > 0) {
    reverse(reversed, line, len);
    printf("%s", reversed);
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

void reverse(char to[], char from[], int len)
{
  int i, j;
  
  for (i=len-2, j=0; i>=0; --i, ++j)
    to[j] = from[i];
  to[j] = '\n';
  ++j;
  to[j] = '\0';
}
