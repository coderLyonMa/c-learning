#include <stdio.h>

unsigned int setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    unsigned u_1 = 0xBBFFDDAA;
    unsigned u_2 = 0xCCFFBBAA;
    unsigned u_3 = 0xEEFFCCAA;

    unsigned u_1_y = 0xFF;
    unsigned u_2_y = 0xBB;
    unsigned u_3_y = 0xDD;

    printf("%x\t%x\t%x\n", u_1, u_1_y, setbits(u_1, 7, 8, u_1_y));
    printf("%x\t%x\t%x\n", u_2, u_2_y, setbits(u_2, 7, 8, u_2_y));
    printf("%x\t%x\t%x\n", u_3, u_3_y, setbits(u_3, 19, 8, u_3_y));
}


unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    // y中最右边n位
    y &= (~0U >> n);
    unsigned z = (y << (p - n + 1)) ;
    return x | z;
    // x取p开始向右n位
}


