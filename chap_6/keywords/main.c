#include <stdio.h>
#include <ctype.h>
#include <debug_macros.h>
#include "getch.h"
#include "keyword.h"

#define MAX_W_LEN 100



int getword(char* word, int max_w_len);
int str_cmp(char* s1, char* s2);
int binsearch(char* word, struct key tab[], int nkeys);


struct key keytab[] = {
    {"auto", 0},
    {"char", 0},
    {"return", 0},
    {"void", 0},
    {"while", 0},
};

//#define NKEYS (sizeof keytab / sizeof key)
#define NKEYS (sizeof keytab / sizeof(struct key))
#define KEYTABSIZE (sizeof keytab)

int main()
{
    char word[MAX_W_LEN];
    int c, n;

    while ((c = getword(word, MAX_W_LEN)) != EOF) {
        if (isalpha(c)) {
            n = binsearch(word, keytab, NKEYS);
            if (n != -1) {
                ++keytab[n].count;
            }
        }
    }

    for (int i = 0; i < NKEYS; ++i) {
        printf("%s %d\n", keytab[i].keyword, keytab[i].count);
    }
    
    return 0;
}


int getword(char* word, int max_w_len)
{
    char* w = word;
    int c;

    while (isspace(c = getch()))
        ;

    // 有3种情况，c是数字，c是字母，c是其他字符
    // 如果是数字的话，期望后面读到的仍然是数字，如果是字母的话，期望后续读到的仍然是字母
    // 最后退出时，会多读取一个字符，需要将该字符压回输入
    if (c != EOF)
        *w++ = c;
    if (!isalnum(c)) {
        *w = '\0';
        return c;
    }

    for (; --max_w_len > 0; ++w)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }

    *w = '\0';
    return *word;
}

int str_cmp(char* s1, char* s2)
{
    for (; *s1 && *s2 && *s1 == *s2; s1++, s2++)
        ;

    return *s1 - *s2;
}

int binsearch(char* word, struct key tab[], int nkeys)
{
    int low, high, half, cond;
    
    low = 0;
    high = nkeys - 1;
    
    while (low <= high) {
        half = (low + high) / 2;
        
        if ((cond = str_cmp(word, tab[half].keyword)) < 0) {
            high = half - 1;
        } else if (cond > 0) {
            low = half + 1;
        } else {
            return half;
        }
    }

    return -1;

}


