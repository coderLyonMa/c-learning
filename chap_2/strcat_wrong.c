#include <stdio.h>
void str_cat(char s[], char t[]);

/*
该版本的输出如下：
omputer
Okcomputer

推断的原因是数组未被分配足够多的空间，每次str_cat调用都会覆盖前者的存储空间
*/

int main()
{
    char a[] = "Hello";
    char b[] = "world";

    char c[] = "Ok";
    char d[] = "computer";

    char e[] = "fine";
    char f[] = "place";

    str_cat(a, b);
    str_cat(c, d);
    str_cat(e, f);

    printf("%s\n", b);
    printf("%s\n", c);
    printf("%s\n", e);
}


void str_cat(char s[], char t[])
{
    int i, j;
    i = j = 0;

    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0')
        ;
}

