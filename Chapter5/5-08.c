/* There is no error checking in day_of_year or month_day. Remedy this
   defect. */

#include <stdio.h>
#include <assert.h>


int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);


static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


main()
{
  int day, pmonth, pday;

  day = day_of_year(2018, 1, 13);
  printf("%d\n", day);

  month_day(2018, day, &pmonth, &pday);
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
    day += daytab[leap][i];
  return day;
}


void month_day(int year, int yearday, int *pmonth, int *pday)
{
  assert(year>=1752);
  assert(yearday>0);
  assert(yearday<=366);
  
  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  for (i = 1; yearday > daytab[leap][i]; i++)
	 yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;
}

       
