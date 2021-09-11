#include <stdio.h>
#define MAX_LEN 0x1EFFFF
#define TO_FIND   234568

/*
Linux支持的数组最大存储空间大概是8Mb
该版本减少了循环内的条件判断次数
执行时间
real	0m0.011s
相比之前吧本，可能快了有0.1s
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

    while (low <= high) {
        mid = (low + high) / 2;
        if (x < a[mid])
            // 因为mid部分已经被检查过了，并且目标值只可能在其左边，所以减一
            high = mid - 1;
        else if (x > a[mid])
            // 目标值只可能在low的右边
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
