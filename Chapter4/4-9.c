/* Our getch and ungetch do not handle a pushed-back EOF
   correctly. Decide what their properties ought to be if an EOF is
   pushed back, then implement your design */

#include <stdio.h>

int getch(void);
void ungetch(int);

main()
{
  int c;

  /* Program does not halt because ungetch does not push EOF onto the
     stack */
  ungetch(EOF);

  while ((c=getch())!=EOF)
    putchar(c);
  
  return 0;
}

/*------------------------------------------------------------------*/
#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else if (c!=EOF)
    buf[bufp++] = c;
}

