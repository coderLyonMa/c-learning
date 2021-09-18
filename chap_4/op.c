#include <ctype.h>

#define NUMBER '0'


char getop(char s[]);


char getop(char s[])
{
    int i = 0;
    int c;

    while ((c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n') {
        s[i] = c;
        i++;
    }

    s[i] = '\0';

    for (i = 0; isdigit(s[i]); i++)
        ;

    if (i != 0 && s[i-1] >= '0' && s[i-1] <= '9')
        return NUMBER;

    if (s[i] == '\n')
        return '\n';

    return s[i];
}
