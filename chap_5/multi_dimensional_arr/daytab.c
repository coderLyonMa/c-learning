#include "daytab.h"


/* 行中的第一列元素的值为0, 这样是为了更加直观地表示月份 */
const static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};


void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i;
    int leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    //for (i = 1; i < 13 && yearday > 0; i++)
    //    yearday -= daytab[leap][i];

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];

    *pmonth = i;
    *pday = yearday;
}

int day_of_year(int year, int month, int day)
{
    int days = 0;
    int leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    for (int i = 1; i < month; i++)
        days += daytab[leap][i];
    days += day;

    return days;
}

void test_daytab(int leap, int m)
{
    char days = daytab[leap][m];
    printf("there're %d days in %s month %d", days, leap ? "leap year" : "", m);

}

