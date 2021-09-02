#include <stdio.h>

int main()
{
    char s[] = "hello\n\0";
    printf("%s", s);
}
