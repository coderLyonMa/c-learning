#include <stdio.h>
#include "lines.h"

int atoi(char*);
int str_cmp(char*, char*);


int main(int argc, char** argv)
{
    int last = 10;
    int maxlines = 1000;
    int max_len = 1000;
    int nlines;
    char* lineptr[maxlines];

    if (argc >= 3) {
        // 对于 argv[1], 其值是一个char*
        // 对于 ++argv, 其值是一个char**，指针前移动并不改变这一事实
        if (str_cmp(*++argv, "-n") == 0)
            last = atoi(*++argv);
    }

    if ((nlines = readlines(lineptr, max_len, maxlines)) == -1)
        return -1;
    
    writellines(lineptr, nlines, last);

    return 0;
}

int atoi(char* s)
{
    int i = 0;
    
    for (i = 0; *s; s++)
        i = i * 10 + *s - '0';

    return i;
}

int str_cmp(char* s1, char* s2)
{
    for (; *s1 && *s2 && *s1 == *s2; s1++, s2++)
        ;
    return *s1 - *s2;
}

