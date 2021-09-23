#include <stdio.h>
#define BUFFSIZE 100

/* 始终指向空闲位置 */
int bufp = 0;

char buffer[BUFFSIZE];

char getch(void)
{
    return (bufp > 0) ? buffer[--bufp] : getchar();
}

void ungetch(char c)
{
    if (bufp > BUFFSIZE)
        printf("buffer max size reached.\n");
    else
        buffer[bufp++] = c;
}
