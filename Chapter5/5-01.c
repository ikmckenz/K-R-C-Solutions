/* As written, getint treats a + or - not followed by a digit as a
   valid representation of zero. Fix it to push such a character back
   on the input. */

#include <ctype.h>
#include <stdio.h>

#define MAX 10

int getint(int *pn);
int getch(void);
void ungetch(int);

main(void)
{
  int c, i, array[MAX];

  for (i=0; i<MAX && (c=getint(&array[i]))!=EOF; ++i)
    printf("%s\n", c==0 ? "Nan" : "Number");

  return 0;
}


int getint(int *pn)
{
  int c, sign;

  while (isspace(c=getch()))
    ;
  if (!isdigit(c) && c!=EOF && c!='+' && c!='-') {
    return 0;
  }
  sign = (c=='-') ? -1 : 1;
  if (c=='+' || c=='-') {
    c = getch();
    if (!isdigit(c)) {
      ungetch((sign==0) ? '+' : '-');
      return 0;
    }
  }
  for (*pn=0; isdigit(c); c=getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c!=EOF)
    ungetch(c);
  return c;
}


int buf[MAX];
int bufp = 0;

int getch(void)
{
  if (bufp > 0) {
    return buf[--bufp];
  }
  else
    return getchar();
}

void ungetch(int c)
{
  if (bufp < MAX)
    buf[bufp++] = c;
}
