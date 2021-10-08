#include <stdio.h>
#include "prt_macros.h"
#include "lines.h"
#include "comp.h"
#include "sort.h"

#define MAXLINE 5000
#define MAX_LEN 1000


int main(int argc, char** argv)
{
    char* lineptr[MAXLINE];
    int nlines, numeric;

    nlines = numeric = 0;

    while (--argc > 0 && *++argv)
        if (str_cmp(*argv, "-n") == 0)
            numeric = 1;

    nlines = readlines(lineptr, MAX_LEN, MAXLINE);

    q_sort((void**) lineptr, 0, nlines - 1,
           (int (*)(void*, void*))(numeric ? num_cmp : str_cmp));

    writelines(lineptr, nlines);

    return 0;
}

