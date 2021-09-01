#include <stdio.h>

int power(int m, int n);

int main()
{
    printf("The result of 1's 10th power operation is %d\n", power(1, 10));
    printf("The result of 2's 10th power operation is %d\n", power(2, 10));
    printf("The result of 9's 3th  power operation is %d\n", power(9, 3));
}

int power(int base, int n)
{
    int result = 1;
    for (int i = n; i > 0; i--)
        result *= base;
    return result;
}
