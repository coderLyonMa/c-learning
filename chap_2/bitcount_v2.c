#include <stdio.h>
int bitcount(unsigned x);

int main()
{
    unsigned u_1 = 0xBBFFDDAA;
    unsigned u_2 = 0xCCFFBBAA;
    unsigned u_3 = 0xEEFFCCAA;
    unsigned u_4 = 0xFF;

    printf("%x\t%d\n", u_1, bitcount(u_1));
    printf("%x\t%d\n", u_2, bitcount(u_2));
    printf("%x\t%d\n", u_3, bitcount(u_3));
    printf("%x\t%d\n", u_4, bitcount(u_4));
}

int bitcount(unsigned x)
{
    int b = 0;

    while (x) {
        x &= (x - 1);
        b++;
    }
    return b;        
}
