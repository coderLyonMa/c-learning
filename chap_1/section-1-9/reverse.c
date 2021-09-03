#include <stdio.h>
#define  MAX_LINES_NUM   100
#define  LINE_MAX_C      1000

int get_line(char s[], int limit);
void reverse(char line[], char reversed[]);
void copy(char from[], char to[]);


int main()
{
    int len, line_num, lines_total;
    len = line_num = lines_total = 0;
    char line[LINE_MAX_C], reversed[LINE_MAX_C], lines[MAX_LINES_NUM][LINE_MAX_C];

    while ((len = get_line(line, LINE_MAX_C)) > 0) {
        lines_total++;
        // 如果长度为1,说明是只有一个换行符的空行，跳过

        reverse(line, reversed);
        copy(reversed, lines[line_num]);
        line_num++;
    }

    // 打印输入分析信息
    printf("%d lines input, shown as below:\n", lines_total);

    for (int i = 0; i < line_num; i++)
        printf("%s", lines[i]);
}


int get_line(char s[], int limit)
{
    int i = 0;
    char c;
    
    // 这里对limit - 1是因为换行符还没放进去
    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < limit - 1; i++)
        s[i] = c;

    // 每行必定有一个换行符
    if (c == '\n') {
        s[i] = c;
        ++i;
        // 到这里，i等于数组长度
    }

    s[i] = '\0';

    return i;
}


void reverse(char line[], char reversed[])
{
    char c;
    int i, idx;
    i = idx = 0;

    // 获取数组长度
    for (i = 0; (c = line[i]) != '\n'; i++)
        ;

    // 将i调整至倒数第一个非空白字符的索引

    for (; i >= 0; i--) {
        reversed[idx] = line[i - 1];
        idx++;
    }

    idx--;
    reversed[idx] = '\n';
    reversed[++idx] = '\0';
}


void copy(char from[], char to[])
{
    int i;
    for (i = 0; from[i] != '\0'; ++i) 
        to[i] = from[i];
    to[++i] = '\0';
}

