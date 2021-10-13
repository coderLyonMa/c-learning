#include <stdio.h>
#include <ctype.h>



int getword(char* word, int lim)
{
    int c, getch();
    void ungetch(int);
    char* w = word;

    // eat consistent space
    while (isspace(c = getch()))
        ;

    // write c into word and move pointer to next available pos
    if (c != EOF)
        *w++ = c;
    // if input is not alpha or num, return this single char
    if (!isalnum(c)) {
        *w = '\0';
        return c;
    }

    // up to lim-1 chars will be write since there've already 1 char been write into <word>
    for (; --lim > 0; ++w)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }

    // last char is not valid word char, so cover it with NULL(it has been ungetch)
    *w = '\0';
    return *word;
}


#define BUFFSIZE 100

static char buff[BUFFSIZE];
char* buffp = buff;

int getch()
{
    return (buffp > buff) ? *--buffp : getchar();
}

void ungetch(int c)
{
    if (buffp < buff + BUFFSIZE) {
        *buffp++ = c;
    } else {
        printf("char buff size exceeded\n");
    }
}
