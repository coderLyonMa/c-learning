#include <stdio.h>

int main()
{
    for (int i = 0; i < lim -1 && (c = getchar()) != '\n' && c != EOF; ++i) {
        s[i] = c;
    }
    int i = 0;
    while (i < lim -1) {
        if ((c = getchar()) == '\n')
            continue;
        if (c == EOF)
            continue;
        s[i] = c;
    }
}
