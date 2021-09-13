#include <stdio.h>
#include <ctype.h>


int atoi(char *s);

int main()
{
    char *s_1 = " -1234";
    char *s_2 = " -987+65";
    char *s_3 = "890384";
    
    printf("%s converted through atoi: %d\n", s_1, atoi(s_1));
    printf("%s converted through atoi: %d\n", s_2, atoi(s_2));
    printf("%s converted through atoi: %d\n", s_3, atoi(s_3));
}

int atoi(char *s)
{
    int i = 0;

    // 跳过空白符
    for (; isspace(*s); s++)
        ;
    // sign在遇到的第一个非空白符号时决定
    int sign = (*s == '-') ? -1 : 1;

    // 指针仍然处在第一个非空白符处，如果它是数字，则符合预期，如果是非数字，则忽略它
    for (; ! isdigit(*s); s++)
        ;

    // 假设数字片段是连续的，如果再出现非数字字符，跳过
    for (; isdigit(*s); s++)
        i = i * 10 + (*s - '0');

    return sign * i;
}

