/* Write the function htoi(s), which converts a string of hexadecimal
digits (including an optional 0x or 0X) into its equivalent integer 
value. The allowable digits are 0 through 9, a through f, and 
A through F. */

#include <stdio.h>
#include <ctype.h>
#include <limits.h>

#define MAXSIZE 18

unsigned long int htoi(char s[], int prefix);

main()
{
  int c, i, prefix;
  char s[MAXSIZE];
  
  for (i=0; (c=getchar()) != EOF; ++i)
    s[i] = tolower(c);

  prefix = 0;
  if (s[0] == '0')
    if (s[1] == 'x')
      prefix = 1;
  
  if ((prefix == 0 && i > MAXSIZE-1) || (prefix == 1 && i > MAXSIZE+1))
    printf("Number too large, don't trust calculation.\n");

  printf("%lu\n", htoi(s, prefix));

  return 0;
}


unsigned long int htoi(char s[], int prefix)
{
  int i;
  unsigned long int number;
  char lower;
  
  number = 0;
  for (i=(2*prefix); isalnum(s[i]); ++i) {
    if (s[i] > 'f')
      printf("Warning: Unrecognized characters.\n");
    if (isdigit(s[i]))
      number = 16 * number + (s[i] - '0');
    else
      number = 16 * number + (s[i] - 'a') + 10;
  }

  return number;
}
      
