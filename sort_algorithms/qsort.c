#include <stdio.h>
#include <stdlib.h>


void q_sort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)
        return;

    /* 将pivot放到最左 */
    swap(v, left, (left + right)/2);

    last = left;
    for (i = left + 1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);

    swap(v, last, left);

    q_sort(v, left, last - 1);
    q_sort(v, last + 1, right);
}

void swap(int v[], int i, int j)
{
    int tmp;
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

