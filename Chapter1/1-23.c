/* Write a program to remove all comments from a C program. Don't forget
to handle quoted strings and character constants properly. C comments do
not nest. */

#include <stdio.h>

main()
{
  int c, comment, test;

  comment = test = 0;
  while ((c=getchar())!=EOF) {
    if (comment==0 && test==0 && c=='/')
      test = 1;
    else if (comment==0 && test==1 && c=='*') {
      comment = 1;
      test = 0;
    }
    else if (comment==0 && test==1 && c!='*') {
      putchar('/');
      putchar(c);
      test = 0;
    }
    else if (comment==1 && test==0 && c=='*')
      test = 1;
    else if (comment==1 && test==1 && c=='/') {
      comment = 0;
      test = 0;
    }
    else if (comment==1 && test==1 && c!='/') {
      putchar('*');
      putchar(c);
      test = 0;
    }
    else if (comment==0 && test==0 && c!='/')
      putchar(c);
  }
  return 0;
}
