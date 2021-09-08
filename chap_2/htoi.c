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
    char h_5[] = "01F2B3c";
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
    int i, c, h;
    i = h = 0;
    
    while ((c = s[i]) != '\0') {
        int add_up = 0;
        if (c == '0' && i == 0) {
            i++;
            continue;
        }
        if (i == 1) {
            if (c != 'x' && c != 'X')
                return 0;
            i++;
            continue;
        }
        if (c >= 'a' && c <= 'f')
            add_up = (c - 'a') + 10;
        else if (c >= 'A' && c <= 'F')
            add_up = (c - 'A') + 10;
        else if (c >= '0' && c <= '9')
            add_up = c - '0';
        else
            return 0;
        h = 16 * h + add_up;
        i++;
    }
    return h;
        
}
