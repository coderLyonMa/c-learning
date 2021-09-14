#include <stdio.h>
#include <ctype.h>

int itoa(char s[]);


int itoa(char s[])
{
    int i = 0;
    int a = 0;
    int sign = 1;

    do {
        if (isspace(s[i]))
            continue;

        if (s[i] == '-') {
            sign = -1;
            continue;
        }

        if (!isdigit(s[i]))
            continue;

        a = a * 10 + s[i] - '0';

    } while (s[i++]);

    return sign * a;
}

