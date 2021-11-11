#include "sort_algorithms.h"
#include "search_algorithms.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>


int* gen_random_arr(int size);
int is_ascending(int a[], int size);

//void load_test(int (*test)(int), int arr_size, int tries);
void load_test(int sort_flag, int arr_size, int tries);

#define QSORT_FLAG 1
#define QSORT_NAME "QUICK SORT"
#define SHELL_SORT_FLAG 2
#define SHELL_SORT_NAME "SHELL SORT"
#define BUBBLE_SORT_FLAG 3
#define BUBBLE_SORT_NAME "BUBBLE SORT"
#define INSERTION_SORT_FLAG 4
#define INSERTION_SORT_NAME "INSERTION SORT"

char* sort_tab[] = {NULL, QSORT_NAME, SHELL_SORT_NAME, BUBBLE_SORT_NAME, INSERTION_SORT_NAME};

int main(int argc, char** argv)
{

    int flag = atoi(argv[1]);
    int size = atoi(argv[2]);
    int ntries = atoi(argv[3]);

    load_test(flag, size, ntries);
    return 0;
}

void load_test(int sort_flag, int size, int tries)
{
    if (sort_tab[sort_flag] == NULL) {
        printf("[ERROR] Invalid sort algorithm flag %d\n", sort_flag);
        return;
    }

    struct timeval before, afer, gap;

    for (int i = 0; i < tries; ++i) {
        int *arr = gen_random_arr(size);

        gettimeofday(&before, NULL);
        switch (sort_flag) {
            case QSORT_FLAG:
                q_sort(arr, 0, size -1);
                break;
            case SHELL_SORT_FLAG:
                shell_sort(arr, size);
                break;
            case BUBBLE_SORT_FLAG:
                bubble_sort(arr, size);
                break;
            case INSERTION_SORT_FLAG:
                insertion_sort(arr, size);
                break;
            default:
                return;
        }
        if (is_ascending(arr, size) == -1) {
            printf("[ERROR] %s test failed in try %d\n", sort_tab[sort_flag], i + 1);
            return;
        }
        gettimeofday(&afer, NULL);
        timersub(&afer, &before, &gap);
        printf("[INFO] test for %s runs in %1ld.%06ld, try %d \n", sort_tab[sort_flag], (long) gap.tv_sec, (long) gap.tv_usec, i + 1);
        free(arr);
    }
    printf("[SUCCESS] %s testing done after %d tries\n", sort_tab[sort_flag], tries);
    return;
}

/* test an array is asc sorted */
int is_ascending(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
        if (arr[i] > arr[i + 1])
            return -1;

    return 0;
}


/* generate an array in size */
int* gen_random_arr(int n)
{
    int* ip = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i)
        ip[i] = rand();

    return ip;
}

