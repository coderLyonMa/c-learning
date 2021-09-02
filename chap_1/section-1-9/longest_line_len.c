#include <stdio.h>
#define LINE_MAX_C 1000

int get_longest_line_len();

int main()
{
    int len, len_max;
    len = len_max = 0;

    // 如果还有未处理的行（这可以通过一个返回行长度的函数来完成，那么对应的条件是如果行长度！=0）
    while (len = get_longest_line_len()) {
        // 如果该行的长度小于目前记录的最长行
        if (len < len_max)
            continue;
        len_max = len;
    }

    printf("The len of longest line input is %d\n", len_max);
}


int get_longest_line_len()
{
    int len = 0;
    char c;
    while ((c = getchar()) != EOF && c != '\n') {
        len++;
    }
    return len;
}

