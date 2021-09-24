#include <stdio.h>
#define MAX_LEN 0x1EFFFF
#define TO_FIND 234568

int binsearch(int a[], int n, int x);
void inita(int a[]);


int main()
{
    int a[MAX_LEN];
    inita(a);
    int find;

    printf("Index of %d in array is : %d\n", TO_FIND, find = binsearch(a, MAX_LEN, TO_FIND));

    printf("Test > a[%d] = %d\n", find, a[find]);

}

void inita(int a[])
{
    int gap = 2;
    
    for (int i = 0; i < MAX_LEN; i++)
        a[i] = i * gap;
}


int binsearch(int v[], int n, int x)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    for (; mid > 0; mid = (low + high) / 2) {
        if (x > v[mid]) {
            low = mid + 1;
        }
        else if (x < v[mid]) {
            high = mid - 1;
        }
        else
            return mid;
    }

    return -1;
}

