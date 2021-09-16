#include <stdio.h>
#include "atof.c"


int main()
{
    char s_a[] = "-1234.567";
    char s_b[] = "1234.567";

    printf("%f\n", atof(s_a));
    printf("%f\n", atof(s_b));
}

