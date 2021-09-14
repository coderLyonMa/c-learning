#include <stdio.h>
#include "reverse.c"

void itoa(int a, char s[], int w);


void itoa(int a, char s[], int w)
{
    int i = 0;
    int c, sign;

    sign = a < 0 ? -1 : 1;

    do {
        c = a % 10;

        if (sign > 0)
            s[i] = c + '0';
        else
            s[i] = (0 - c) + '0';

        i++;

    } while (a /= 10);

    if (sign < 0)
        s[i++] = '-';

    for (; i < w; i++)
        s[i] = ' ';


    //reverse(s);
    s[i] = '\0';
    reverse(s);

}

