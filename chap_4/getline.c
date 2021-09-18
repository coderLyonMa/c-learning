#include <stdio.h>

int get_line(char line[], int max);


int get_line(char line[], int max)
{
    int c;
    for (int i = 0; (line[i] = (c = getchar())) != EOF && i < max - 1; i++)
        if (c == '\n') {
            line[++i] = '\0';
            return i;
        }

    return 0;
}
