/* Rewrite the function lower, which converts upper case letters
to lower case, with a conditional expression instead of if-else.*/

#include <stdio.h>

main()
{
  int i;
  char s[] = "HeLlO wOrLd";

  for (i=0; s[i]!='\0'; ++i)
    putchar((s[i] >= 'A' && s[i] <= 'Z') ? s[i]+'a'-'A' : s[i]);

  putchar('\n');

  return 0;
}
