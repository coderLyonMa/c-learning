#include <stdio.h>

#define IN  1 /* in a word  */
#define OUT 0 /* out of a word */


int main()
{
    int c;
    int w_num = 0;
    int state = OUT;

    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            continue;
        } else {
            if (state == IN)
                continue;
            if (state == OUT) {
                ++w_num;
                state = IN;
            }
        }
    }
    printf("There're %d word(s) input\n", w_num);
}
