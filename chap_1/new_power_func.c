#include <stdio.h>

int power (int m, int n);


int main()
{
    for (int i = 0; i < 10; i++) {
        printf("The result of 3's %d th power operation is %d\n", i, power(3, i));
        printf("The result of -2's %d th power operation is %d\n", i, power(-2, i));
    }
}

int power(int base, int n)
{
    int result = 1;
    for (int j = n; j > 0; j--)
        result = result * base;
    return result;
}

