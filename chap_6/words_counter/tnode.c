#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct tnode {
    char* word;
    long count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode* addtree(struct tnode* p, char* word)
{
    int str_cmp(char*, char*);
    char* str_dup(char*);
    struct tnode* talloc();
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(word);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = str_cmp(word, p->word)) == 0) {
        ++p->count;
    } else if (cond < 0) {
        p->left = addtree(p->left, word);
    } else {
        p->right = addtree(p->right, word);
    }

    return p;
}

void treeprint(struct tnode* p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4ld %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

struct tnode* talloc()
{
    return (struct tnode*) malloc(sizeof(struct tnode));
}


char* str_dup(char* s)
{
    char* p;
    
    p = (char*) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}


int str_cmp(char* s1, char* s2)
{
    for (; *s1 && *s2 && *s1 == *s2; ++s1, ++s2)
        ;
    return *s1 - *s2;
}

