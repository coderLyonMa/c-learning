#include <stdio.h>
#include "calc.h"
#define BUFFSIZE 100

/* 始终指向空闲位置 */
int bufp = 0;

char buf[BUFFSIZE];

char getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(char c)
{
    if (bufp > BUFFSIZE)
        printf("buffer max size reached.\n");
    else
        buf[bufp++] = c;
}

