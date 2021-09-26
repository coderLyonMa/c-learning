#include <stdio.h>
#include "alloc.h"

static char allocbuff[ALLOCSIZE];
char* p = &allocbuff[0];


char* alloc(int n)
{
    if (&allocbuff[0] + ALLOCSIZE >= p + n) {
        p += n;
        return p - n;
    } else {
        printf("no more space to assign\n");
        return 0;
    }
}

void afree(char* pa)
{
    if (p >= &allocbuff[0] && p <= &allocbuff[0] + ALLOCSIZE)
        p = pa;
    else
        printf("illegal pointer val");
}
