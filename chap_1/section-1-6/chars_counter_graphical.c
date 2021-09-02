#include <stdio.h>

int main()
{
    long white_c, other_c, total_c;
    white_c = other_c, total_c = 0;
    char c;
    long num_c_bucket[10];

    for (int i = 0; i <= 9; i++)
        num_c_bucket[i] = 0;

    // input loop
    while ((c = getchar()) != EOF) {
        total_c++;

        if (c >= '0' && c <= '9')
            num_c_bucket[c - '0']++;
        else if (c == ' ' || c == '\t' || c == '\n')
            white_c++;
        else
            other_c++;
    }

    printf("\n#################Input char statistic show as below###############\n");
    
    printf("white spaces: ");
    for (; white_c > 0; white_c--)
        printf("#");
    printf("\n");

    printf("other characters input: ");
    for (; other_c > 0; other_c--)
        printf("#");
    printf("\n");

    printf("\n");
    printf("---------And numeric chars statistic show as below-----------------\n");
    for (int i = 0; i <= 9; i++) {
         
        printf("Number %d input: ", i);
        for (; num_c_bucket[i] > 0; num_c_bucket[i]--)
            printf("#");
        printf("\n");
    }
}

