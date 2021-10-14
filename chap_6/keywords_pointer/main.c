#include <debug_macros.h>
#include <stdio.h>
#include <ctype.h>
#include "getch.h"


struct key {
    char* word;
    int count;
};

struct key keytab[] = {
    {"auto", 0}, {"break", 0}, {"case", 0}, {"char", 0},
    {"const", 0}, {"continue", 0}, {"default", 0}, {"do", 0},
    {"double", 0}, {"else", 0}, {"enum", 0}, {"extern", 0},
    {"float", 0}, {"for", 0}, {"goto", 0}, {"if", 0},
    {"int", 0}, {"long", 0}, {"register", 0}, {"return", 0},
    {"short", 0}, {"signed", 0}, {"sizeof", 0}, {"static", 0},
    {"struct", 0}, {"switch", 0}, {"typedef", 0}, {"union", 0},
    {"unsigned", 0}, {"void", 0}, {"volatile", 0}, {"while", 0},
};

#define NKEYS (sizeof keytab / sizeof (struct key))

#define MAXW 100

int getword(char*, int);
struct key* binsearch(char* w, struct key keytab[], int n);

int main()
{
    int c, n;

    char word[MAXW];
    struct key* keyptr;

    while ((c = getword(word, MAXW)) != EOF) {
        if (isalpha(c))
            if ((keyptr = binsearch(word, keytab, NKEYS)) != NULL)
                ++keyptr->count;
    }

    for (keyptr = keytab; keyptr < keytab + NKEYS; ++keyptr) {
        printf("%12s\t%d\t", keyptr->word, keyptr->count);
        if ((keyptr - keytab + 1) % 4 == 0 && keyptr != keytab)
            printf("%c", '\n');
    }

    return 0;
}


int getword(char* word, int lim)
{
    char* w = word;
    int c;

    // 吞掉空白符
    while (isspace(c = getch()))
        ;

    // 先把这个字符放进来再说
    if (c != EOF)
        *w++ = c;
    // 单字符的情况
    if (!isalnum(c)) {
        *w = '\0';
        // 注意，这里返回的是c，而不是*w/*word（考虑到c 为EOF 的情况）
        return c;
    }

    for (; --lim > 0; ++w)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }

    // 压回的字符在这里被覆盖
    *w = '\0';
    return *word;
}

struct key*
binsearch(char* w, struct key keytab[], int n)
{
    int str_cmp(char*, char*);
    int cond;

    struct key *low, *high, *mid;
    low = &keytab[0];
    high = &keytab[n - 1];

    while (low <= high) {
        mid = low + (high - low) / 2;

        cond = str_cmp(w, mid->word);
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

int str_cmp(char* s1, char* s2)
{
    for (; *s1 && *s2 && *s1 == *s2; ++s1, ++s2)
        ;
    return *s1 - *s2;
}

