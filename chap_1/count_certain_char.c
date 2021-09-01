#include <stdio.h>

int main()
{
    int c;
    long count_tab = 0, count_line = 0, count_space = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++count_line;
        } else if (c == ' ') {
            ++count_space;
        } else if (c == '\t') {
            ++count_tab;
        }
    }
    printf("There're %ld spaces from the input\n", count_space);
    printf("There're %ld tabs from the input\n", count_tab);
    printf("There're %ld lines from the input\n", count_line);
}
