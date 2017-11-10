/* Write the function strend(s,t), which returns 1 if the string t
   occurs at the end of the string s, and zero otherwise. */

#include <stdio.h>
#include <string.h>

int strend(char *, char *);


int main(void)
{
  char s[] = "Testing 123";
  char t[] = "123";

  printf("%d\n",strend(s,t));

  return 0;
}


int strend(char *s, char *t)
{
  int diff = strlen(s) - strlen(t);
  if (diff>=0) {
      s += diff;
      while(*s++ == *t++){
	if(!*s)
	  return 1;
      }
  }
  return 0;
}
