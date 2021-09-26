#include "sort_lines.h"


void q_sort(char* v[], int left, int right)
{
    int i, last;

    if (left >= right)
        return;

    swap(v, left, (left + right)/2);

    last = left;

    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);

    swap(v, left, last);

    q_sort(v, left, last-1);
    q_sort(v, last+1, right);
}

int strcmp(char* s, char* t)
{
    while (*s == *t) {
        s++;
        t++;
    }

    return *s - *t;
}

void swap(char* s[], int i, int j)
{
    char* tmp;
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}

