#include "bubble_sort.h"

void bubble_sort(int v[], int n)
{
    int i, j, tmp;

    for (i = 1; i < n; i++)
        for (j = 0; j < n - i; j++)
            if (v[j] > v[j+1])
                tmp = v[j], v[j] = v[j+1], v[j+1] = tmp;
}
