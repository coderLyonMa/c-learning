#include <stdio.h>

/*
该版本的htoi只支持最长32位的hex字符转换
*/

int htoi(char h[]);

int main()
{
    char h_1[] = "0xFFFF";
    char h_2[] = "0X0001";
    char h_3[] = "0xQQQQ";
    char h_4[] = "0x1F2B3c";
    char h_5[] = "01F2 B3c";
    char h_6[] = "0x1F2B3c00";


    printf("%s\t htoi: %d\n", h_1, htoi(h_1));
    printf("%s\t htoi: %d\n", h_2, htoi(h_2));
    printf("%s\t htoi: %d\n", h_3, htoi(h_3));
    printf("%s\t htoi: %d\n", h_4, htoi(h_4));
    printf("%s\t htoi: %d\n", h_5, htoi(h_5));
    printf("%s\t htoi: %d\n", h_6, htoi(h_6));
}

int htoi(char s[])
{
    int i, decimal;
    i = decimal = 0;
    char upper[] = "0X";
    char lower[] = "0x";

    // 匹配hex前缀
    for (i = 0; (s[i] == upper[i] || s[i] == lower[i]) && i < 2; i++)
        ;
    // 如果未匹配
    if (i != 2)
        return 0;

    while (s[i] != '\0') {
        int hex = 0;

        if (s[i] >= 'a' && s[i] <= 'f')
            hex = (s[i] - 'a') + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            hex = (s[i] - 'A') + 10;
        else if (s[i] >= '0' && s[i] <= '9')
            hex = s[i] - '0';
        else
            hex = 0;

        if (s[i] == '\0')
            return decimal;

        decimal = decimal * 16 + hex;
        i++;
    }
    return decimal;   
}
