/* Write a pointer version of the function strcat that we showed in
   Chapter 2: strcat(s,t) copies the string t to the end of s. */

#include <stdio.h>

void strcat2(char *s, char *t);


int main(void)
{
  char s[200] = "hello ";
  char t[] = "world!";

  strcat2(s,t);
  printf("%s\n",s);

  return 0;
}


void strcat2(char *s, char *t)
{
  /* Go to the end of s */
  while(*s++)
    ;
  /* Go back one to account for \0 */
  *s--;
  /* Copy t to the end of s */
  while(*s++ = *t++)
    ;
}
