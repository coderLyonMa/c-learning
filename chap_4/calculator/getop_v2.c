#include <ctype.h>
#include <stdio.h>
#include "calc_v2.h"
#include "getch.c"


int getop(char s[])
{
    static int i, c;

    // 如果是空白符，跳过
    while ((s[0] = c = getch()) != ' ' && s[0] != '\t')
        ;

    // op 有几种可能性：数字，算数操作符，换行符
    // pattern like '.1234' not supported 
    if (!isdigit(s[0]))
        return s[0];

    i++;

    while (isdigit(c = getch()))
        s[i++] = c;

    if (c == '.')
        s[i] = c;

    while (isdigit(c = getch()))
        s[i++] = c;

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}
