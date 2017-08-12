/* Write the function strrindex(s,t), which returns the
position of the rightmost occurrence of t in s, or -1 if
there is none. */

#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";


main()
{
  char line[MAXLINE];
  int found = 0;
  int position;

  while (getline(line, MAXLINE) > 0) {
    position = strrindex(line, pattern);
    printf("%s", line);
    printf("The start of the rightmost occurrence is: %d\n", position);
    found++;
    }
  return found;
}

int getline(char s[], int lim)
{
  int c, i;

  i = 0;
  while(--lim>0 && (c=getchar())!=EOF && c!='\n')
    s[i++] = c;
  if (c=='\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

int strrindex(char s[], char t[])
{
  int i, j, k, rightmost;

  rightmost = -1;
  for (i=0; s[i]!='\0'; i++) {
    for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
      ;
    if (k>0 && t[k]=='\0')
      rightmost = i;
  }
  return rightmost;
}
