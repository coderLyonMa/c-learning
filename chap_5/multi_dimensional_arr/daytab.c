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

    if (!is_legal_yearday(year, yearday)) {
        *pmonth = 0;
        *pday = 0;
        return;
    }

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];

    *pmonth = i;
    *pday = yearday;
}

int day_of_year(int year, int month, int day)
{
    int days = 0;
    int leap = is_leap_year(year);

    if (!is_legal_ymd(year, month, day))
        return -1;

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

int is_legal_ymd(int year, int month, int m_day)
{
    char legal_month = 1 <= month && month <= 12;

    if (!legal_month)
        return 0;

    int leap = is_leap_year(year);

    char legal_m_day = 0 < m_day && m_day <= daytab[leap][month];
    if (!legal_m_day)
        return 0;

    return 1;
}

int is_leap_year(int year)
{
    return year%4 == 0 && year%100 != 0 || year%400 == 0;
}

int is_legal_yearday(int year, int yearday)
{
    int max_days = 0;
    int leap = is_leap_year(year);
    
    for (int i = 1; i <= 12; i++)
        max_days += daytab[leap][i];

    return 0 < yearday && yearday <= max_days;
}

