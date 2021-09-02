#include <stdio.h>

int main()
{
    long white_c, tab_c, nline_c, other_c, total_c;
    white_c = tab_c = nline_c = other_c, total_c = 0;
    char c;
    long num_c_bucket[10];

    for (int i = 0; i <= 9; i++)
        num_c_bucket[i] = 0;

    // input loop
    while ((c = getchar()) != EOF) {
        total_c++;

        if (c >= '0' && c <= '9')
            num_c_bucket[c - '0']++;
        else if (c == ' ')
            white_c++;
        else if (c == '\t')
            tab_c++;
        else if (c == '\n')
            nline_c++;
        else
            other_c++;
    }

    printf("\n#################Input char statistic show as below###############\n");
    printf("%ld white spaces input\n", white_c);
    printf("%ld tabs input\n", tab_c);
    printf("%ld new line input\n", nline_c);
    printf("%ld other characters input\n", other_c);

    printf("\n");
    printf("---------And numeric chars statistic show as below-----------------\n");
    for (int i = 0; i <= 9; i++)
        printf("number [%d] input: %ld\n", i, num_c_bucket[i]);

}
