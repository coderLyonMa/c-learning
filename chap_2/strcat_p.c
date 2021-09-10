#include <stdio.h>
#define MAXCHAR 100
void str_cat(char s[], char t[]);

/*
该版本为前一个字符分配了足够多的空间，修复了wrong版本的问题

*/

int main()
{
    char a[MAXCHAR] = "Hello";
    char *b = "world";

    char c[MAXCHAR] = "Ok";
    char *d = "computer";

    char e[MAXCHAR] = "fine";
    char *f = "place";

    str_cat(a, b);
    str_cat(c, d);
    str_cat(e, f);

    printf("%s\n", a);
    printf("%s\n", c);
    printf("%s\n", e);
}


void str_cat(char *s, char *t)
{
    while (*++s != '\0')
        ;
    while (*s++ = *t++)
        ;
}

