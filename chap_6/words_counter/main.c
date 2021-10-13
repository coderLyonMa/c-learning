#include <stdio.h>
#include <ctype.h>
#include <debug_macros.h>

#include "tnode.h"
#include "getword.h"

#define MAXWORD 100

int main()
{
    struct tnode *root = NULL;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
        root = addtree(root, word);

    treeprint(root);
    
    return 0;
}

