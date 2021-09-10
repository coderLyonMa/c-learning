#include <stdio.h>
unsigned invert(unsigned x, int p, int n);

int main()
{
    unsigned u_1 = 0xBBFFDDAB;
    unsigned u_2 = 0xCCFFBBCD;
    unsigned u_3 = 0xEEFFCCEF;

    printf("%x\t%x\n", u_1, invert(u_1, 3, 4));
    printf("%x\t%x\n", u_2, invert(u_2, 7, 8));
    printf("%x\t%x\n", u_3, invert(u_3, 7, 8));
}


unsigned invert(unsigned x, int p, int n)
{
    // 1. 截取位 2. 求反 3. x与(y << (p - n + 1)) | 运算

    unsigned y = ~(x >> (p - n + 1)) & ~(~0 << n);
    printf("%u\n", y);

    return x ^ (y << (p - n + 1));
}
