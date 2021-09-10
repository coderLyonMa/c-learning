#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main()
{
    unsigned u_1 = 0xBBFFDDAA;
    unsigned u_2 = 0xCCFFBBAA;
    unsigned u_3 = 0xEEFFCCAA;

    printf("%x\t%x\n", u_1, getbits(u_1, 7, 8));
    printf("%x\t%x\n", u_2, getbits(u_2, 7, 8));
    printf("%x\t%x\n", u_3, getbits(u_3, 19, 8));
}

unsigned getbits(unsigned x, int p, int n)
{
    // 01101101
    // 00p + p0
    // 循环：按位&右边的n位，右操作数为1
    //  可以得到全1的位模式
    // 1. 只要右起的 （p + 1）
    //  000111...(p + 1)个1
    // x & ~(~0U << (p + 1)) 丢掉左边的位
    // 2. 只要 p 数起的 右边 n位（丢掉右边的若干位，该位数可以通过 >> (p + n -1)）
    
    // 1. 把左边的位通过移位丢弃掉
    // 2. 通过&运算把左边的位丢弃掉
    x = ((x >> (p + 1 - n)) & ~(~0 << n));
    return x;
}

