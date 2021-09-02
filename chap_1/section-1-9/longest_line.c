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
// 所以，将其设为一个全局变量


int get_line(char s[], int limit);
void copy(char from[], char to[]);

int main()
{
    char line[LINE_MAX_C];
    char longest[LINE_MAX_C];

    int len, len_max;
    len = len_max = 0;

    while ((len = get_line(line, LINE_MAX_C)) > 0) {
        if (len <= len_max)
            continue;
        len_max = len;
        copy(line, longest);
    }

    printf("\n");
    printf("The longest line input show as below:\n%s", longest);
    printf("And the len of the longest line is: %d\n", len_max);
}


int get_line(char line[], int limit)
{
    int len = 0;
    char c;

    while ((c = getchar()) != EOF && c != '\n' && len < limit) {
        line[len] = c;
        len++;
    }
    // 要特别注意这段边界条件的处理
    if (c == '\n') {
        line[len++] = c;
    }
    // 以及这里，该字符不应该被计入行长度
    line[len + 1] = '\0';

    return len;
}

void copy(char from[], char to[])
{
    int i;
    for (i = 0; from[i] != '\0'; i++) 
        to[i] = from[i];
    to[i++] = '\0';
}

