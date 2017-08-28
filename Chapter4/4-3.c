/* Given the basic framework, it's straightforward to extend the
   calculator. Add the modulus (%) operator and provisions for
   negative numbers. */

/* To compile using GCC link the math library for fmod by using 
gcc -ansi 4-3.c -lm */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

main()
{
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
	push(pop() / op2);
      else
	printf("error: zero divisor\n");
      break;
    case '%':
      op2 = pop();
      if (op2!=0.0)
	push(fmod(pop(), op2));
      else
	printf("error: zero divisor\n");
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}


#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}


#include <ctype.h>
int getch(void);
void ungetch(int);

int getop(char s[])
{
  int i, c, next;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c!='.' && c!='-')
    return c;
  if (c=='-') {
    next = getch();
    if (!isdigit(next) && next!='.')
      return c;
    if (next!=EOF)
      ungetch(next);
  }
  i = 0;
  if (isdigit(c) || c=='-')
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c=='.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c!=EOF)
    ungetch(c);
  return NUMBER;
}


#define BUFSIZE 100
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
