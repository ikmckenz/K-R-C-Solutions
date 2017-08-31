/* Add commands for handling variables. (It's easy to provide
   twenty-six variables with single-letter names.) Add a variable for
   the most recently printed value. */

/* To compile using GCC, link the math library for fmod by using gcc
   -ansi 4-X.c -lm */

/* The variable 'a' refers to the last printed item. The main switch
   will substitute the last printed value for a and then calculate as
   normal. For memory I've created the variables x, y, and z, which
   can be assigned values with the '=' operator. This assignment is
   not commutative, and the variable should come first. For example,
   "x 1 =" sets x to the value 1. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
void printtop(void);
void swap(void);
void duplicate(void);
void clear(void);

double last = 0;
char vars[3];
int varpoint; 

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
    case 's':
      push(sin(pop()));
      break;
    case 'c':
      push(cos(pop()));
      break;
    case 'e':
      push(exp(pop()));
      break;
    case '^':
      op2 = pop();
      push(pow(pop(), op2));
      break;
    case 'a':
      push(last);
      break;
    case 'x':
    case 'y':
    case 'z':
      varpoint = type - 'x';
      push(vars[varpoint]);
      break;
    case '=':
      vars[varpoint] = pop();
      break;
    case 'p':
      printtop();
      break;
    case '\n':
      last = pop();
      printf("\t%.8g\n", last);
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

void printtop(void)
{
  if (sp>0)
    printf("The top element of the stack is: %.8g\n", val[sp-1]);
  else
    printf("error: stack empty\n");
}

void swap(void)
{
  double temp1 = pop();
  double temp2 = pop();
  push(temp1);
  push(temp2);
}

void duplicate(void)
{
  double temp = pop();
  push(temp);
  push(temp);
}

void clear(void)
{
  sp = 0;
}

/*------------------------------------------------------------------*/

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

/*------------------------------------------------------------------*/

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
