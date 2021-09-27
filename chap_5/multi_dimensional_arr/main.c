#include "daytab.h"
#include "main.h"

void main()
{
    int month, day;
    month_day(2021, 365, &month, &day);

    dprint(month);    
    dprint(day);
}

