#include <stdio.h>

#define BUFFSIZE 100


static char buff[BUFFSIZE];
char* buffp = buff;


int getch()
{
    return (buffp > buff) ? *--buffp : getchar();
}

void ungetch(int c)
{
    if (buffp >= buff + BUFFSIZE) {
        printf("buff size exceeded\n");
    } else {
        *buffp++ = c;
    }
}

