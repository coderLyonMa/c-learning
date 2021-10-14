#include <stdlib.h>
#include <stdio.h>
#include "words_tree.h"



int str_len(String);

String str_dup(String s);
void str_cpy(String s, String t);
int str_len(String str);
int str_cmp(String s1, String s2);



Tnode* addtree(Tnode* node, String word)
{
    String sp;
    int cond;
//    printf("adding tree node, word: %s\n", word);

    if (node == NULL) {
        node = talloc();
        if (node == NULL || (node->word = str_dup(word)) == NULL)
            return NULL;

        str_cpy(node->word, word);
        ++node->count;
        node->left = NULL;
        node->right = NULL;

    } else if ((cond = str_cmp(word, node->word)) < 0) {
        node->left = addtree(node->left, word);
    } else if (cond > 0) {
        node->right = addtree(node->right, word);
    } else {
        if ((node->word = str_dup(word)) == NULL)
            return NULL;
        str_cpy(node->word, word);
        ++node->count;
    }

    return node;
}


void printtree(Tnode* node)
{
    if (node != NULL) {
        printtree(node->left);
        printf("%s: %ld\n", node->word, node->count);
        printtree(node->right);
    }
}


Tnode* talloc()
{
    return (Tnode*) malloc(sizeof(Tnode));
}


String str_dup(String s)
{

    return (String) malloc(str_len(s));
}

void str_cpy(String s, String t)
{
    while (*s++ = *t++)
        ;
}

int str_len(String str)
{
    String s = str;
    while (*s)
        ++s;

    return s - str;
}

int str_cmp(String s1, String s2)
{
    for (; *s1 && *s2 && *s1 == *s2; ++s1, ++s2)
        ;
    return *s1 - *s2;
}

