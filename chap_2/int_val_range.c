#include <stdio.h>

/*****
该程序假设了不同类型的整形在机器上实现的位数
*****/

int main()
{

    // char 默认是有符号的，所以signed可以省略
    char min_char, max_char;    
    for (char i = 0; i >= 0; i++)
        max_char = i;
    for (char i = 0; i <= 0; i--)
        min_char = i;

    unsigned char u_min_char = 0;
    unsigned char u_max_char = 0 - 1;

    printf("Min signed char:\t%d\n", min_char);
    printf("Max signed char:\t%d\n", max_char);
    printf("Min unsigned char:\t%d\n", u_min_char);
    printf("Max unsigned char:\t%d\n", u_max_char);

    short int min_short, max_short;
    for (short i = 0; (max_short = i) >= 0; i++)
        ;
    for (short i = 0; (min_short = i) <= 0; i--)
        ;
    unsigned short u_short_min = 0;
    unsigned short u_short_max = 0 - 1;

    printf("Min signed short int:\t%d\n", min_short);    
    printf("Max signed short int:\t%d\n", max_short);
    printf("Min unsigned short int:\t%d\n", u_short_min);    
    printf("Max unsigned short int:\t%d\n", u_short_max);

    int min_int = 1U << 31;
    int max_int = (0U - 1U) >> 1;
    unsigned int u_min_int = 0;
    unsigned int u_max_int = 0 - 1;
    // todo 这里没看懂
    // whatever 注意格式化符号

    printf("Min signed int:\t%d\n", min_int);
    printf("Max signed int:\t%d\n", max_int);
    printf("Min unsigned int:\t%u\n", u_min_int);
    printf("Max unsigned int:\t%u\n", u_max_int);

    long long_max = (0UL - 1UL) >> 1;
    long long_min = 1UL << 63;
    unsigned long u_long_min = 0;
    unsigned long u_long_max = 0 - 1;

    printf("Min signed long int:\t%ld\n", long_min);    
    printf("Max signed long int:\t%ld\n", long_max);
    printf("Min unsigned long int:\t%lu\n", u_long_min);    
    printf("Max unsigned long int:\t%lu\n", u_long_max);

}
