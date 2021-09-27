#include "utils.h"
#include <stdio.h>
#include <ctype.h>

int get_line(char* line, int max)
{
    int c, i;
    i = 0;

    while ((c = getchar()) != EOF && c != '\n' && i < max - 1) {
        *line = c;
        line++;
        i++;
    }

    if (c == '\n') {
        *line = c;
        i++;
    }

    *++line = '\0';
    return i;
}


void reverse(char* s)
{
    char *s0 = s;
    char tmp;

    for (; *s; s++)
        ;
    s--;

    for (; s >= s0; s--, s0++)
        tmp = *s, *s = *s0, *s0 = tmp;
}

int strindex(char* s, char* t)
{
    char *i, *j, *s0;
    // i代替s在内层向前遍历
    // j代替t在最内层向前遍历

    for (s0 = s; *s; s++)
        for (i = s, j = t; *j && *i == *j; i++, j++)
            if (*(j+1) == '\0')
                return s - s0;

    return -1;
}

int str_ncmp(char* s, int n, char* t)
{
    if (!n)
        return n;

    for (; n > 1 && *(s+1) && *(t+1); n--)
        s++, t++;

    return *s - *t;
}

int getop()
{
}

int atoi(char *s)
{
    int i;

    while (isspace(*s))
        s++;

    int sign = (*s == '-') ? -1 : 1;

    if (!isdigit(*s)) {
        s++;
    }

    for (i = 0; isdigit(*s); s++)
        i = i * 10 + (*s - '0');

    return i * sign;
}

void itoa(int i, char* s)
{

    int c;
    int j = 0;

    while (i) {
        c = i % 10 + '0';
        s[j++] = c;
        i /= 10;
    }
    s[j] = '\0';
    reverse(s);
}

