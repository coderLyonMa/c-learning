#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 0x1EFFFF

void initv(int v[], int n);
void prt_arr(int v[], int n);
void shellsort(int v[], int n);

int v[MAX_SIZE];
static int foo = 9;


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
    int gap, i, j, temp;
    // gap 被初始化为长度一半处
    gap = n / 2;

    while (gap > 0) {
        i = gap;

        while(i < n) {
            // j的初始值为0
            j = i - gap;

            // 初始情况，j（初始情况，0） 和 j+gap索引（初始情况，一半位置）比较大小
            while (j >= 0 && v[j] > v[j+gap]) {

                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;

                j-=gap;
            }

            i++;
        }

        gap /=2;
    }
}
