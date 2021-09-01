#include <stdio.h>

int main()
{
    int c;
    long nl;

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++nl;
    }
    printf("There're %1.ld line(s) input\n", nl);
}
