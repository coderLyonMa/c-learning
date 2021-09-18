#include <stdio.h>

int strrindex(char s[], char t[]);


int strrindex(char s[], char t[])
{
    int i, l;

    for (i = 0; s[i] != '\0'; i++)
        ;
    
    l = i;

    for (; i >= 0; i--)
        for (int k = i, j = 0; s[k] == t[j] || t[j] == '\0'; k++, j++)
            if (t[j] == '\0' && j > 0)
                return k - j;

    return -1;
}

