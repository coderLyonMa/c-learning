#include <stdio.h>
#define MAX_LEN 0x1EFFFF
#define TO_FIND 234568

/*
Linux支持的数组最大存储空间大概是8Mb
*/

int binsearch(int a[], int x, int n);
void inita(int a[]);


int main()
{
    int a[MAX_LEN];
    inita(a);

    printf("Index of %d in array is : %d\n", TO_FIND, binsearch(a, TO_FIND, MAX_LEN));

}

void inita(int a[])
{
    int gap = 2;
    
    for (int i = 0; i < MAX_LEN; i++)
        a[i] = i * gap;
}

int binsearch(int a[], int x, int n)
{
    int low, mid, high;
    low = 0;
    high = n - 1;
    mid = (n - 1) / 2;

    while (low <= high && a[mid] != x) {

        if (x < a[mid])
            // 因为mid部分已经被检查过了，并且目标值只可能在其左边，所以减一
            high = mid - 1;
        else
            // 目标值只可能在low的右边
            low = mid + 1;
        mid = (low + high) / 2;
    }
    if (a[mid] == x)
        return mid;
    return -1;
}
