#include <stdio.h>

int main()
{
    int i, c;
    int limit = 1000;
    char s[];
    for (i = 0; (c = getchar()) != EOF; i++) {
        if (c == '\n')
            break;
        if (!(i < limit - 1))
            break;
        if (c == '\n')
            break;
        i++;
        s[i] = c;
    }
}

