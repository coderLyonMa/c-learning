#include <stdio.h>

#define BUFFSIZE 10

static char buff[BUFFSIZE];
char* buffp = &buff[0];

char getch(void)
{
    return (buffp > buff) ? *--buffp : getchar();
}

void ungetch(int c)
{
    if (buffp >= buff + BUFFSIZE) {
        printf("buff overflow\n");
    } else {
        *buffp++ = c;
    }
}

