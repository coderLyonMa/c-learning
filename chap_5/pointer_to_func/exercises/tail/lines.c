#include <stdio.h>
#include "alloc.h"

#define MAXLINE 1000

void str_cpy(char*, char*);
int get_line(char*, int);

int readlines(char** lineptr, int max_len, int maxlines)
{
    int nlines = 0;
    int len;
    char* p, line[MAXLINE];

    while (len = get_line(line, max_len)) {
        if (nlines > maxlines || (p = alloc(len)) == NULL)
            return -1;

        line[len - 1] = '\0';
        str_cpy(line, p);
        *lineptr++ = p;
        nlines++;
    }

    return nlines;
}

int writellines(char** lineptr, int nlines, int last)
{
    for (; nlines >= 0 && (nlines - last) > 0; --nlines, lineptr++)
        ;

    for (; nlines-- > 0; )
        printf("%s\n", *lineptr++);
}


int get_line(char* line, int max_len)
{
    int c;
    char* line_0 = line;

    while ((c = getchar()) != EOF && c != '\n' && (line - line_0) < max_len - 1)
        *line++ = c;

    if (c == '\n')
        *line++ = c;

    *line = '\0';
    return line - line_0;
}

void str_cpy(char* s, char* t)
{
    while (*t++ = *s++)
        ;
}

