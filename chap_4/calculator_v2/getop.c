#include <ctype.h>
#include <stdio.h>
#include "calc.h"


char getop(char s[])
{
    static int i, c;

    // 如果是空白符，跳过
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    // op 有几种可能性：数字，算数操作符，换行符
    // pattern like '.1234' not supported 
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;

    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}
