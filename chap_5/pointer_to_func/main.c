#include <stdio.h>
#include "prt_macros.h"
#include "lines.h"
#include "comp.h"
#include "sort.h"
#include "utils.h"

#define MAXLINE 5000
#define MAX_LEN 1000


int main(int argc, char** argv)
{
    char* lineptr[MAXLINE];
    int nlines, numeric, reverse;

    nlines = numeric = reverse = 0;

    while (--argc > 0 && **++argv == '-')
        while (*(++*argv))
            switch (**argv) {
            case 'n':
                numeric = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            default:
                break;
        }


    nlines = readlines(lineptr, MAX_LEN, MAXLINE);

    q_sort((void**) lineptr, 0, nlines - 1,
           (int (*)(void*, void*))(numeric ? num_cmp : str_cmp));

    if (reverse)
        reverse_arr((void **)lineptr);

    writelines(lineptr, nlines);

    return 0;
}

