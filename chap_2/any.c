#include <stdio.h>


int any(char s[], char p[]);


int main()
{
    
    char a[] = "Hello world";
    char pattern_a[] = "wo";

    char b[] = "Ok google";
    char pattern_b[] = "lE";

    char c[] = "Ok computer";
    char pattern_c[] = "te";

    char d[] = "This world is a fine place";
    char pattern_d[] = "is";

    printf("index of <%s> in <%s> is %d\n", pattern_a, a, any(a, pattern_a));
    printf("index of <%s> in <%s> is %d\n", pattern_b, b, any(b, pattern_b));
    printf("index of <%s> in <%s> is %d\n", pattern_c, c, any(c, pattern_c));
    printf("index of <%s> in <%s> is %d\n", pattern_d, d, any(d, pattern_d));
}


int any(char s[], char p[])
{
    int i, a, j;

    for (i = 0; s[i] != '\0'; i++) {
        for (a = i, j = 0; s[a] == p[j]; a++, j++)
            ;
        if (p[j] == '\0')
            return i;
    }
    return -1;
}
