#include <stdio.h>
#define IN  1
#define OUT 0
#define MAX_W_LEN 100


int main()
{
    char c;
    int state = OUT;
    long w_len_tmp = 0;
    long w_len_bucket[MAX_W_LEN];

    for (int i = 0; i < MAX_W_LEN; i++)
        w_len_bucket[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n' && c != ',' && c!= '.' && c != ':') {
            state = IN;
            w_len_tmp++;
        }
        else {
            state = OUT;
            w_len_bucket[w_len_tmp]++;
            w_len_tmp = 0;
        }
    }


    for (int i = 0; i < MAX_W_LEN; i++)
        if (w_len_bucket[i])
            printf("There're %ld words with %d characters\n", w_len_bucket[i], i);
}

