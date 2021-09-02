#include <stdio.h>
#define LINE_MAX_C 1000

// 千言万语一句话：C语言中，字符数组/数组，是不能直接作为参数返回的

// 原初的想法是：有4个函数
// main()
// get_line() 返回字符数组（一行）
// get_len(char s[]) 返回这个字符数组的长度
// get
// 这样声明一个返回字符数组的函数是不可行的
//
//
char s[] get_line();
int get_line_len(char s[]);

int main()
{
    int len, len_max;
    len = len_max = 0;

    printf("The len of longest line input is ");
}


char s[] get_line()
{
    int len = 0;
    char c;

    while ((c = getchar()) != EOF && c != '\n') {
        len++;
    }

    return len;
}

