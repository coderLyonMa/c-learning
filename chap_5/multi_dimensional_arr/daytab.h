#include <stdio.h>

void test_daytab(int leap, int m);
void month_day(int year, int yearday, int *pmonth, int *pday);
int day_of_year(int year, int month, int day);
int is_leap_year(int year);

int is_legal_yearday(int year, int yearday);
int is_leap_year(int year);
int is_legal_ymd(int year, int month, int m_day);
