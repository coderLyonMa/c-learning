#include <stdio.h>

int main ()
{
    int c;
    int former_char;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (former_char == ' ') {
                continue;
            }
        }
        printf("%c", c);
        former_char = c;
    }
}

