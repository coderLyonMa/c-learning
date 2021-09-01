#include <stdio.h>

int main()
{
    int c;
    int nc;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c = EOF) {
            break;
        }
    }
    printf("%d\n", nc);
}
