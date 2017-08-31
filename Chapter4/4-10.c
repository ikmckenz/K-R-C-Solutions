/* An alternate organization uses getline to read an entire input
   line; this makes getch and ungetch unneccessary. Revise the
   calculator to use this approach. */

/* To compile using GCC, link the math library by using 
   gcc -ansi 4-10.c -lm */

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

int getline(char [], int);

double last = 0;
char vars[3];
int varpoint;

char line[MAXOP];
int lineidx;

main()
{
  int type;
  double op2;
  char s[MAXOP];

  while (getline(line, MAXOP)!=0) {
    lineidx = 0;
    while ((type = getop(s)) != '\0') {
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

int getop(char s[])
{
  int c, i;
  
  while ((s[0] = c = line[lineidx++]) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c!='.')
    return c;
  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = line[lineidx++]))
      ;
  if (c=='.')
    while (isdigit(s[++i] = c = line[lineidx++]))
      ;
  s[i] = '\0';
  lineidx--;
  
  return NUMBER;
}

/* getline from page 29 */
int getline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
      s[i] = c;
    if (c=='\n') {
      s[i] = c;
      ++i;
    }
    s[i] = '\0';
    return i;
}
