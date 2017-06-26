/* Write a program to determine the ranges of char, short int and long
variables, both signed and unsigned, by printing appropriate values from
standard headers and by direct computation. */

/* I use GCC so I referenced this:
https://www.gnu.org/software/libc/manual/html_node/Range-of-Type.html */

#include <stdio.h>
#include <limits.h>

main()
{
  printf("The minimum value that can be represented by a signed char is: %d\n", SCHAR_MIN);
  printf("The maximum value that can be represented by a signed char is: %d\n", SCHAR_MAX);

  printf("The maximum value that can be represented by a unsigned char is: %d\n", UCHAR_MAX);
  printf("The minimum value that can be represented by a char is: %d\n", CHAR_MIN);

  printf("The maximum value that can be represented by a char is: %d\n", CHAR_MAX);
  printf("The minimum value that can be represented by a signed short int is: %d\n", SHRT_MIN);

  printf("The maximum value that can be represented by a signed short int is: %d\n", SHRT_MAX);

  printf("The maximum value that can be represented by a unsigned short int is: %d\n", USHRT_MAX);
  printf("The minimum value that can be represented by a signed int is: %d\n", INT_MIN);
  printf("The maximum value that can be represented by a signed int is: %d\n", INT_MAX);

  printf("The maximum value that can be represented by a unsigned int is: %u\n", UINT_MAX);

  printf("The minimum value that can be represented by a signed long int is: %ld\n", LONG_MIN);
  printf("The maximum value that can be represented by a signed long int is: %ld\n", LONG_MAX);
  
  printf("The maximum value that can be represented by a unsigned long int is: %lu\n", ULONG_MAX);

  /* The following statements will only compile without the -ansi flag.

  printf("The minimum value that can be represented by a signed long long int is: %lld\n", LLONG_MIN);
  printf("The maximum value that can be represented by a signed long long int is: %lld\n", LLONG_MAX);

  printf("The maximum value that can be represented by a unsigned long long int is: %llu\n", ULLONG_MAX); */
  
  return 0;
}
