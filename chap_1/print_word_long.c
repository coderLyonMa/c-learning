#include <stdio.h>
#define IN  1
#define OUT 0

int main()
{
    static int nlwords[100];
    int c, state, len;
    c = len = 0;
    state = OUT;

    /* read input from stdin and count the lenght of the word  */
    while ((c = getchar()) != EOF) {
        if (state == IN)
        {
            if (c != ' ' && c != '.' && c != ':' && c != '\t' && c != '\n' && c!= '!')
                ++len;
            else
            {
                ++nlwords[len];
                state = OUT;
                len = 0;
            }

        }
        if (state == OUT)
        {
            if (c != ' ' && c != '.' && c != ':' && c != '\t' && c != '\n' && c!= '!')
            {
                state = IN;
                len = 1;
            }
        }
    
    }

    for (int i = 0; i <= 100; i++) {
        if (nlwords[i] == 0)
            continue;

        printf("Words in length of [LEN: %d]", i);
        for (int j = 0; j <= nlwords[i]; j++)
            printf("#");
        printf("\n");
    }

}

