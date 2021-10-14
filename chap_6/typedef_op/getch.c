#include <stdio.h>

#define BUFFSIZE 100

static char buff[BUFFSIZE];
char* buffp = buff;

int getch(void)
{
    return (buffp > buff) ? *--buffp : getchar();
}

void ungetch(char c)
{
    if (buffp < buff + BUFFSIZE)
        *buffp++ = c;
    else
        printf("buff size exceeded\n");
}

