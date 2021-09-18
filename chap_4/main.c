#include <stdio.h>
#include "getline.c"
#include "atof_sci.c"
#include "atof.c"
#define MAXLINE 1000



int main()
{
    char line[MAXLINE];
    int len;
    double sum = 0.0;
    double atof_sci(char s[]);

    while (len = get_line(line, MAXLINE)) {
        sum += atof_sci(line);
        printf("sum is %.10f\n", sum);
    }

}

