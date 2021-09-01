#include <stdio.h>

int power(int m, int n);

int main()
{
    for (int i = 0; i < 10; i++) {
        printf("The result of 4's %d th power operation is %d.\n",  i, power(4, i));
        printf("The result of -2's %d th power operation is %d.\n", i, power(-2, i));
    }
}

int power(int base, int n)
{
    int ret = 1;
    while (n > 0) {
        ret *= base;
        n--;
    }
    return ret;
}

