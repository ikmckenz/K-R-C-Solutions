/* Modify getop so that it doesn't need to use ungetch. */

#include <ctype.h>
#include <stdio.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
int getch(int);

main()
{
  int type;
  char s[MAXOP];
  
  while ((type=getop(s)) != EOF) {
    if (type=='a')
      printf("Received.");
    else
      putchar(type);
  }
}

int getop(char s[])
{
  int c, i;
  static int buff = EOF;

  while ((s[0] = c = getch(buff)) == ' ' || c == '\t')
    buff = EOF;
  buff = EOF;
  s[1] = '\0';
  
  if (!isdigit(c) && c != '.')
    return c;
  i = 0;
  if (isdigit(c)) {
    while (isdigit(s[++i] = c = getch(buff)))
      ;
  }
  if (c == '.') {
    while (isdigit(s[++i] = c = getch(buff)))
      ;
  }
  s[i] = '\0';
  if (c != EOF)
    buff = c;
  return NUMBER;
}


int getch(int buff)
{ 
  if (buff==EOF) {
    return getchar();
  }
  else {
    return buff;
  }
}
