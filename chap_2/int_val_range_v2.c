#include <stdio.h>

/*****
该程序相比int_val_range具有可移植性
U后缀不可缺少的原因在于：如果没有U后缀，机器可能会对操作数进行算数右移
对于pritnf函数，u for decimal unsigned int， d for decimal unsinged int
*****/

int main()
{

    // char 默认是有符号的，并且总是非负值，所以signed可以省略
    // 这种写法总是具有可移植性（除非某台机器上实现的char类型是64位
    char min_char, max_char;    
    for (char i = 0; i >= 0; i++)
        max_char = i;
    for (char i = 0; i <= 0; i--)
        min_char = i;
    // unsigned char 很少使用
    unsigned char u_min_char = 0;
    unsigned char u_max_char = 0 - 1;

    printf("Min signed char:\t%d\n", min_char);
    // 011111...
    printf("Max signed char:\t%d\n", (char) ((unsigned char)(~0U) >> 1));
    printf("Min unsigned char:\t%d\n", (unsigned char) 0);
    printf("Max unsigned char:\t%d\n", (unsigned char)(~0U));

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

    printf("Min signed int: \t%d\n", ~(~0U >> 1));
    printf("Max signed int: \t%d\n", ~0U >> 1);
    printf("Min unsigned int:\t%u\n", 0);
    // 这里的u也是不可缺省的，因为%d格式化的是一个有符号的十进制数，但是U后缀可以省略
    printf("Max unsigned int:\t%u\n", ~0);

    // 100000...
    // 011111...
    // 111111 >> 1
    // 这里的U和L都不可缺少, 因为 0U的字面值是一个unsigned int，uppercast 到long之后会在左边补0
    printf("Min signed long:\t%ld\n", ~(~0UL >> 1));
    printf("Max signed long:\t%ld\n", ~0UL >> 1);
    printf("Min unsigned long:\t%lu\n", 0L);    
    printf("Max unsigned long:\t%lu\n", ~0UL);

}
