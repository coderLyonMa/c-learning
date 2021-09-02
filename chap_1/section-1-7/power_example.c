#include <stdio.h>


int power(int base, int n);


int main()
{
    int base = 3;
    for (int i = 0; i < 10; i++)
        printf("base: %d, n: %d, power: %d\n", base, i, power(base, i));
}


int power(int base, int n)
{
    int p = 1;
    for (int i = 0; i < n; i++)
        p = base * p;
    return p;
}
