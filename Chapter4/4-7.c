/* Write a routine ungets(s) that will push back an entire string onto
   the input. Should ungets know about buf and bufp, or should it just
   use ungetch? */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BUFSIZE 100
int getch(void);
void ungetch(int);
void ungets(char s[]);

main()
{
  char s[] = "Hello world!";
  int c, i;

  ungets(s);
  for (i=0; i<=strlen(s); ++i)
    putchar(getch());
  putchar('\n');
    
  return 0;
}

/*------------------------------------------------------------------*/

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

void ungets(char s[])
{
  int i = strlen(s);
  
  while (i >= 0)
    ungetch(s[i--]);
}

