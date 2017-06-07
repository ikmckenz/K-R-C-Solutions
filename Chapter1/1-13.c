/* Write a program to print a histogram of the lengths of words in its input. */

#include <stdio.h>

main()
{
  int i, j, c, count;
  int nchar[10];

  count = 0;
  for (i = 0; i < 10; ++i)
    nchar[i] = 0;
  
  while ((c = getchar()) != EOF) {
    if (c == ' ' | c == '\n') {
      if (count <= 9)
	++nchar[count];
      else
	++nchar[10];
      count = 0;
    }
    else
      ++count;
  }
  for (i = 1; i < 10; ++i) {
    printf("%d | ", i);
    printf("%d | ", nchar[i]);
    for (j = 0; j < nchar[i]; ++j)
      printf("-");
    printf("\n");
  }
}
