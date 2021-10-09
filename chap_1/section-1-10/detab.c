#include <stdio.h>

#define TABW 8

int main()
{
    int c, pos;

    pos = 1;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            pos = 1;
            putchar(c);
        }
        else if (c == '\t') {
            for (int ns = TABW - ((pos - 1) % TABW); ns > 0; --ns) {
                ++pos;
                putchar(' ');
            }
        }
        else {
            ++pos;
            putchar(c);
        }
    }

    return 0;
}

