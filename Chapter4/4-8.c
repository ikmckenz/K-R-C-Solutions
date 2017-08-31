/* Suppose that there will never be more than one character of
   pushback. Modify getch and ungetch accordingly. */

#include <stdio.h>

int getch(void);
void ungetch(int);

main()
{
  int c;

  /* This replaces any '\' character with a '*' character using
     ungetch to show it is working as intended */
  while ((c = getch()) != EOF) {
    if (c == '\\') 
      ungetch('*');
    else
      putchar(c);               
  }
    
  return 0;
}

/*------------------------------------------------------------------*/

int buf;
int bufp = 0;

int getch(void)
{
  if (bufp > 0) {
    bufp = 0;
    return buf;
  }
  else
    return getchar();
}

void ungetch(int c)
{
  if (bufp > 0)
    printf("ungetch: no character to un-get\n");
  else {
    buf = c;
    bufp++;
  }
}
