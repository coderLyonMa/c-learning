#include <stdio.h>
#define MAX_LEN 1000
#define TABW 8


int main()
{
    int c, pos;
    
    pos = 1;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            pos = 1, putchar(c);
        } else if (c == '\t') {
            int ns = TABW - ((pos - 1) % TABW);
            for (; ns > 0; --ns, putchar(' '), ++pos)
                ;
        } else {
            ++pos;
            putchar(c);
        }
    }
}

