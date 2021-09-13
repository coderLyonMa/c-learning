#include <stdio.h>
#include "reverse_example.c"
#define STRLENMAX 1000

int main()
{
    char s_a[STRLENMAX] = "hello world!";
    char s_b[STRLENMAX] = "ok google! ";

    reverse(s_a);
    reverse(s_b);

    printf("%s\n", s_a);
    printf("%s\n", s_b);

}

