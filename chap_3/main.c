#include <stdio.h>
#include "atoi_dowhile.c"
#define MAXLEN 1000


int main()
{
    int i_a = 123456;
    int i_b = ~(~0U >> 1) + 1;
    char s_a[MAXLEN];
    char s_b[MAXLEN];

    atoi(i_a, s_a);
    atoi(i_b, s_b);

    printf("%d\tconverted: %s\n", i_a, s_a);
    printf("%d\tconverted: %s\n", i_b, s_b);
}

