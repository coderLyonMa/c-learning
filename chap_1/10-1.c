#include <stdio.h>

int main ()
{
    int c;
    int print_char;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
            continue;
        } else if (c == '\b') {
            printf("\\b");
            continue;
        }
        printf("%d", c);
    }
}

