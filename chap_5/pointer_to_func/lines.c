#include <stdio.h>
#include "lines.h"
#include "alloc.h"

#define MAX_LEN 10000

static char line[MAX_LEN];

int readlines(char** lineptr, int max_len, int maxline)
{
    int nlines = 0;
    int len;
    char* p;

    if (max_len > MAX_LEN) {
        printf("Error: max %d chars supported for each line only\n", MAX_LEN);
        return -1;
    }

    while (len = get_line(line, max_len)) {
        if (nlines > maxline - 1 || (p = alloc(len)) == NULL)
            return -1;

        line[len-1] = '\0';
        str_cpy(line, p);
        *lineptr++ = p;
        nlines++;
    }

    return nlines;
}

void writelines(char** lineptr, int nlines)
{
    while (--nlines >= 0)
        printf("%s\n", *lineptr++);
}


int get_line(char* line, int max_len)
{
    char c;
    char *line_0 = line;
    
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

