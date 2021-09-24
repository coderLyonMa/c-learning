#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "bubble_sort.h"
#include "binsearch.h"
#include "qsort.h"

//int v[MAX_SIZE];
void test();
void prt_arr(int v[], int n);


int main()
{
    for (int i = 0; i < 10; i++)
        test();
}

void test()
{
    int v[MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; i++)
        v[i] = (int) random();

    //q_sort(v, 0, MAX_SIZE-1);
    bubble_sort(v, MAX_SIZE);

    int target = (int) random();

    int index = binsearch(v, target, MAX_SIZE);

    if (index != -1 && v[index] != target)
        printf("qsort bug found!");
    else if (index == -1)
        return;
}

