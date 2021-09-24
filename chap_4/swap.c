#include <stdio.h>
#define swap(t, x, y) {t tmp; tmp = x; x = y; y = tmp;}
#define dprint(expr) printf(#expr ": %ld\n", expr)


int main()
{
    long a = 0x1EFD;
    long b = 0x1EED;
    swap(long, a, b);

    dprint(a);
    dprint(b);
}
