#include <stdio.h>
#include "get_line.h"


int get_line(char line[], int max)
{
    int i = 0;
    int c;

    while ((c = getchar()) != EOF && c != '\n' && i < max - 1)
        line[i++] = c;
    
    if (c == '\n') {
        line[i] = c;
        i++;
    }

    line[i] = '\0';
    return i;
}
