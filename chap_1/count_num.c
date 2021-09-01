#include <stdio.h>


int main ()
{
    int c;
    static int ndigit[10];

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++ndigit[c - '0'];
        }
    }
    for (int i = 0; i < 10; i++) {
        if (ndigit[i] != 0)
            printf("There're %d [digit %d] input\n", ndigit[i], i);
    }
}
