/* Write a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab
stops as for detab. */

#include <stdio.h>

#define MAXLINE 1000
#define TABWIDTH 4

int getline(char line[], int maxline);
void entab(char tabbed[], int len);


main()
{
  int len;
  char line[MAXLINE];

  while ((len = getline(line, MAXLINE)) > 0)
    entab(line, len);
  
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

 
void entab(char tabbed[], int len)
{
  int c, i, j, blanks;

  blanks = 0;
  for (i=0; i<len-1; ++i) {
    c = tabbed[i];
    if (c == ' ') {
      ++blanks;
      if (blanks == TABWIDTH) {
	putchar('\t');
	blanks = 0;
      }
    }
    else {
      for (j=0; j<blanks; ++j)
	putchar(' ');
      blanks = 0;
      putchar(c);
    }
  }
  putchar('\n');
}
