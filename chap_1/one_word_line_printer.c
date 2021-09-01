#include <stdio.h>
#define IN  1
#define OUT 0
#define LINEMAXC 1000 

int main()
{
    char c;
    int state = OUT;
    char line[LINEMAXC];
    int i = 0;

    // get char loop
    while ((c = getchar()) != EOF) {
        // if any of following char is encountered, prt new line
        if (c == ' ' || c == '\t' || c == '.' || c == ',' || c == ':')
            printf("\n");
        else
            putchar(c);
    }
    printf("\n");


}

