/* Rewrite the routines day_of_year and Month_day with pointers
   instead of indexing. */

#include <stdio.h>
#include <assert.h>


int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);


/* This is ugly but I think it's what the book wants. */
int err[] = {0};
int jan[] = {31};
int feb[] = {28, 29};
int mar[] = {31};
int apr[] = {30};
int may[] = {31};
int jun[] = {30};
int jul[] = {31};
int aug[] = {31};
int sep[] = {30};
int oct[] = {31};
int nov[] = {30};
int dec[] = {31};

int *daytab[] = {
  err, jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};


main()
{
  int year, day, pmonth, pday;

  year = 2016; 			/* This was a leap year */
  day = day_of_year(year, 3, 13);
  printf("%d\n", day);
  
  month_day(year, day, &pmonth, &pday);
  printf("%d, %d\n", pmonth, pday);

  year = 2018; 			/* This is not a leap year */
  day = day_of_year(year, 3, 13);
  printf("%d\n", day);
  
  month_day(year, day, &pmonth, &pday);
  printf("%d, %d\n", pmonth, pday);
}


int day_of_year(int year, int month, int day)
{
  assert(year>=1752);
  assert(month>0);
  assert(month<13);
  assert(day>0);
  assert(day<32);
  
  int i, leap;
  
  leap = (year%4 == 0) && (year%100 != 0) || (year%400 == 0);
  for (i = 1; i < month; i++)
    day += daytab[i][i==2 && leap];
  return day;
}


void month_day(int year, int yearday, int *pmonth, int *pday)
{
  assert(year>=1752);
  assert(yearday>0);
  assert(yearday<=366);
  
  int i, leap;
  
  leap = (year%4 == 0) && (year%100 != 0) || (year%400 == 0);
  for (i = 1; yearday > daytab[i][i==2 && leap]; i++) {
    yearday -= daytab[i][i==2 && leap];
  }
  *pmonth = i;
  *pday = yearday;
}

