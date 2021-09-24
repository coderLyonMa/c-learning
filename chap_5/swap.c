#include <stdio.h>
#define dprint(expr) printf(#expr ":\t%d\n", expr)
// #define prt(statment) { printf("#statment" "\n"); statement; }

void swap(int *a, int *b);


int main()
{
    int a = 1;
    int b = 2;
    printf("before swap\n");
    dprint(a);
    dprint(b);
    swap(&a, &b);
    printf("after swap\n");

    dprint(a);
    dprint(b);
}

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
