#include <stdio.h>

void str_cpy(char* s, char* t)
{
    while (*t++ = *s++)
        ;
}

int get_line(char* line, int maxline)
{
    char c;
    char* line_0 = line;

    while ((c = getchar()) != EOF && c != '\n' && (line - line_0) < maxline - 1)
        *line++ = c;

    if (c == '\n')
        *line++ = c;

    *line = '\0';

    return line - line_0;
}

int str_cmp(char *s1, char *s2)
{
    for (; *s1 == *s2 && *s1 && *s2; s1++, s2++)
        ;

    return *s1 - *s2;
}

int strindex(char* s, char* pattern)
{
    char *s0 = s;
    char *i, *j;
    
    for (s0 = s; *s; s++)
        for (i = s, j = pattern; *i == *j; i++, j++)
            if (*(j+1) == '\0' && (j + 1 - pattern) > 0)
                return s - s0;

    return -1;
}
