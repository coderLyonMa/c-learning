#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 0x1EFFF

void initv(int v[], int n);
void prt_arr(int v[], int n);
void q_sort(int v[], int left, int right);
void swap(int v[], int i, int j);

int v[MAX_SIZE];


int main()
{
    initv(v, MAX_SIZE);

    q_sort(v, 0, MAX_SIZE-1);

    prt_arr(v, MAX_SIZE);
}


void initv(int v[], int n)
{
    for (int i = 0; i < n; i++)
        v[i] = (int) random();
}

void prt_arr(int v[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\n", v[i]);
}


void q_sort(int v[], int left, int right)
{
    int i, last;

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

