#include <ctype.h>

#include <debug_macros.h>

#include "getch.h"
#include "words_tree.h"

#define MAXWORD 100


int getword(char* word, int lim);


int main()
{
    Tnode* root = NULL;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
        // 这里赋值的意义在于初始化指针
        root = addtree(root, word);

    printtree(root);
}


int getword(char* word, int lim)
{
    int c;
    char* w = word;

    while (isspace(c = getch()))
        ;

    if (c != EOF)
        *w++  = c;

    if (!isalnum(c)) {
        *w = '\0';
        return c;
    }

    // max (lim - 1) chars
    for (; --lim > 0; ++w)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }

    *w = '\0';
    return *word;
}

