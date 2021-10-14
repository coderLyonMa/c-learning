/* 使用了typedef 关键字的 keyword 统计程序 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <debug_macros.h>

#include "getch.h"


typedef struct key {
    char* word;
    long count;
} Key;

Key keytab[] = {
    {"auto", 0}, {"break", 0}, {"case", 0}, {"char", 0},
    {"const", 0}, {"continue", 0}, {"default", 0}, {"do", 0},
    {"double", 0}, {"else", 0}, {"enum", 0}, {"extern", 0},
    {"float", 0}, {"for", 0}, {"goto", 0}, {"if", 0},
    {"int", 0}, {"long", 0}, {"register", 0}, {"return", 0},
    {"short", 0}, {"signed", 0}, {"sizeof", 0}, {"static", 0},
    {"struct", 0}, {"switch", 0}, {"typedef", 0}, {"union", 0},
    {"unsigned", 0}, {"void", 0}, {"volatile", 0}, {"while", 0},
};

#define NKEYS (sizeof keytab / sizeof(Key))
#define MAXWORD 100

typedef char* String;

int main()
{
    Key* keyp;
    char word[MAXWORD];
    Key* binsearch(char*, Key [], int);
    int getword(char*, int);

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((keyp = binsearch(word, keytab, NKEYS)) != NULL)
                ++keyp->count;

    for (keyp = keytab; keyp < keytab + NKEYS; ++keyp) {
        printf("%12s:\t %ld\t", keyp->word, keyp->count);
        if ((keyp - keytab + 1) % 4 == 0)
            printf("\n");
    }
}

Key* binsearch(char* word, Key tab[], int n)
{
    Key *low, *high, *mid;
    low = &tab[0];
    high = &tab[n-1];
    int cond;
    
    while (low <= high) {
        mid = low + (high - low) / 2;
        cond = strcmp(word, mid->word);
        if (cond < 0) {
            high = mid - 1;
        } else if (cond > 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return NULL;
}

int getword(char* word, int lim)
{
    int c;
    char* w = word;

    while (isspace(c = getch()))
        ;
        
    if (c != EOF)
        *w++ = c;
        
    if (!isalnum(c)) {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; ++w)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }

    *w = '\0';
    return *word;
}

