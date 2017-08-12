/* Extend atof to handle scientific notation of the form
123.45e-6, where a floating-point number may be followed by
e or E and an optionally signed exponent. */

#include <ctype.h>
#include <stdio.h>

double atof(char s[]);


main()
{
  char test[] = "123.456789e-6";

  printf("%.20f\n", atof(test));

  return 0;
}


double atof(char s[])
{
  double val, power;
  int i, j, sign, sci;

  for (i=0; isspace(s[i]); i++)
    ;
  sign = (s[i]=='-') ? -1 : 1;
  if (s[i]=='+' || s[i]=='-')
    ++i;
  for (val=0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i]=='.')
    i++;
  for (power=1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  val = sign * val / power;
  
  if (s[i]=='e' || s[i]=='E') {
    ++i;
    sign = (s[i]=='-') ? -1 : 1;
    if (s[i]=='+' || s[i]=='-')
      ++i;
    for (sci=0; isdigit(s[i]); i++)
      sci = 10 * sci + (s[i] - '0');
    sci *= sign;
    if (sci > 0)
      while (sci > 0) {
	val *= 10.0;
	--sci;
      }
    else if (sci < 0)
      while (sci < 0) {
	val /= 10.0;
	++sci;
      }
  }
  return val;
}
