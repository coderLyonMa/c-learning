#include "daytab.h"
#include "main.h"

void main()
{
    int month, day;
    month_day(2020, 367, &month, &day);
    dprint(day_of_year(2021, 12, 3));

    int max;
    dprint(month);    
    dprint(day);
    //dprint(max = is_legal_yearday(2020, 1));
}

