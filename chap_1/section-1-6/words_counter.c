#include <stdio.h>
#define OUT 0
#define IN  1

int main()
{
    long cc, nc, wc;
    cc = nc = wc = 0;
    int state = OUT;
    char c;

    while ((c = getchar()) != EOF) {
        // char input, cc incre
        cc++;
        if (c == '\n')
            // if new line is input, nc incre
            nc++;
        if (c == ' ' || c == '\n' || c == '\t')
            // if none of the above char input, out of word
            state = OUT;
        else {
            // else in word
            if (state == OUT)
                // if state is OUT(but now in), wc incre
                wc++;
            // else in word so set state as IN
            state = IN;
        }
    }

    printf("\n");
    printf("%ld characters input\n", cc);
    printf("%ld words input\n", wc);
    printf("%ld lines input\n", nc);
}

