/* Write getfloat, the floating-point analog of getint. What type does
   getfloat return as its function value? */

/* Don't input .1, input 0.1 instead. */

#include <ctype.h>
#include <stdio.h>

#define MAX 10

int getch(void);
void ungetch(int);
int getfloat(double*);

main(void)
{
  double flt;
  int result;
  result = getfloat(&flt);
  printf("Result: %f\n", flt);
  return 0;
}

int getfloat(double *pn)
{
  int c, sign;
  int count, period;
  count = period = 0;

  while(isspace(c = getch()))
    ;
  if(!isdigit(c) && c!=EOF && c!='+' && c!='-' && c!='.') {
    ungetch(c);
    return 0;
  }
  sign = (c=='-') ? -1 : 1;
  if (c=='+' || c=='-') {
    c = getch();
    if (!isdigit(c) && c!='.') {
      ungetch((sign==0) ? '+' : '-');
      return 0;
    }
  }
  for (*pn = 0; isdigit(c) || c=='.'; c = getch()) {
    if (c!='.') {
      *pn = 10 * *pn + (c-'0');
      count++;
    }
    else if (c=='.') {
      period = count;
    }
  }
  if (period==0) {
    period = count;
  }
  period = count - period;
  while (period!=0) {
    *pn = *pn / 10.0;
    period--;
  }
  *pn = *pn * sign;

  if (c!=EOF) {
    ungetch(c);
  }
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
