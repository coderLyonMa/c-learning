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
    int nlines, numeric, reverse, case_sen;
    int (*comp)(void*, void*);

    nlines = numeric = reverse = case_sen = 0;

    while (--argc > 0 && **++argv == '-')
        while (*(++*argv))
            switch (**argv) {
            case 'n':
                numeric = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            case 'f':
                case_sen = 1;
                break;
            default:
                break;
        }

    if (numeric)
        comp = (int (*)(void*, void*)) num_cmp;
    else {
        if (case_sen)
            comp = (int (*)(void*, void*)) str_fcmp;
        else
            comp = (int (*)(void*, void*)) str_cmp;
    }

    nlines = readlines(lineptr, MAX_LEN, MAXLINE);

    q_sort((void**) lineptr, 0, nlines - 1, 
           comp);

    if (reverse)
        reverse_arr((void **)lineptr);

    writelines(lineptr, nlines);

    return 0;
}

