#include <stdio.h>



int main()
{
    int c, nwhite, nother;
    nwhite = nother = 0;

    int ndigit[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };

    while ((c = getchar()) != EOF) {
        switch (c) {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                ndigit[c - '0']++;
                break;
            case ' ': case '\n': case '\t':
                nwhite++;
                break;
            default:
                nother++;
                break;
        }
    }

    printf("\n#################Input char statistic show as below###############\n");
    printf("%d white spaces input\n", nwhite);
    printf("%d other characters input\n", nother);

    printf("\n");
    printf("---------And numeric chars statistic show as below-----------------\n");
    for (int i = 0; i <= 9; i++)
        printf("number [%d] input: %d\n", i, ndigit[i]);

    return -1;
}

