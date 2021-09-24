#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 0x1EFFFF

void initv(int v[], int n);
void prt_arr(int v[], int n);
void shellsort(int v[], int n);

int v[MAX_SIZE];


int main()
{
    initv(v, MAX_SIZE);

    shellsort(v, MAX_SIZE);

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


void shellsort(int v[], int n)
{
    int tmp, j, k, gap;

    for (gap = n / 2; gap > 0; gap /= 2)
        for (j = gap; j < n; j++)
            for (k = j - gap; k >= 0 && v[k] > v[k+gap]; k -= gap)
                tmp = v[k], v[k] = v[k+gap], v[k+gap] = tmp;
/*            for (k = j - gap; k >= 0 && v[k] > v[k+gap]; k -= gap)
                tmp = v[k], v[k] = v[k+gap], v[k+gap] = tmp;
*/
 /*       for (j = gap; j < n; j++) {
            int k = j - gap;
            if (v[k] > v[k+gap])
                tmp = v[k], v[k] = v[k+gap], v[k+gap] = tmp;
        }
*/
}

