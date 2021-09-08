#include <stdio.h>

void foo(char s[]);


int main()
{
    char str_1[] = "hello";
    foo(str_1);
    printf("%s", str_1);
}

void foo(const char s[])
{
    s[1] = 'a';
}
