/* Rewrite the temperature conversion program of Section 1.2 
to use a function for conversion. */

#include <stdio.h>

float celcius(float);

float celcius(float fahr)
{
  return (5.0/9.0) * (fahr-32.0);
}


main()
{
  float fahr;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    printf("%3.0f %6.1f\n", fahr, celcius(fahr));
    fahr = fahr + step;
  }
}

