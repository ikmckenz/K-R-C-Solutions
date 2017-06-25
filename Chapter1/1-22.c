/* Write a program to "fold" long input lines into two or more shorter
lines after the last non-blank character that occurs before the n-th
column of input. Make sure your program does something intelligent with
very long lines, and if there are no blanks or tabs before the specified
column. */

/* This program can correctly handle long lines with no spaces or long
lines with normal sized words with spaces. It cannot handle lines with
both words longer than LONGLINE and spaces. */

#include <stdio.h>

#define MAXLINE 1000
#define LONGLINE 80

int getline(char line[], int maxline);
int countblanks(char line[], int len);
void printfancy(char line[], int len);
void printsolid(char line[], int len);


main()
{
  int i, len, blanks;
  char line[MAXLINE];

  while ((len = getline(line, MAXLINE)) > 0) {
    blanks = countblanks(line, len);
    if (len<=LONGLINE && len>1)
      printf("%s", line);
    else if (len>LONGLINE && blanks > 0)
      printfancy(line, len);
    else
      printsolid(line, len);
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


int countblanks(char line[], int len)
{
  int i, blanks;

  blanks = 0;
  for (i=0; i<len; ++i)
    if (line[i] == ' ')
      ++blanks;
  return blanks;
}


void printfancy(char line[], int len)
{
  int i, j, blank;

  i = j = blank = 0;
  while (i<len) {
    while (i<(j*LONGLINE)) {
      if (line[i] == ' ')
	blank = i;
      ++i;
    }
    if (blank>0)
      line[blank] = '\n';
    ++j;
  }
  printf("%s", line);
}
    
  

void printsolid(char line[], int len)
{
  int i, j, wrap;
  
  wrap = len / LONGLINE;
  for (i=0; i<=wrap; ++i) {
    for (j=0; j<=LONGLINE-1 && j+(i*LONGLINE)<len; ++j)
      putchar(line[(j+(i*LONGLINE))]);
    if (i!=wrap)
      putchar('\n');
  }
}
      

