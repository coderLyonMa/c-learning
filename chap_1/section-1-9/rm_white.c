#include <stdio.h>
#define  MAX_LINES_NUM   100
#define  LINE_MAX_C      1000

int get_line(char s[], int limit);
int trim(char line[]);
void copy(char from[], char to[]);


int main()
{
    int len, trimed_len, line_num, lines_total;
    len = trimed_len = line_num = lines_total = 0;
    char line[LINE_MAX_C], lines[MAX_LINES_NUM][LINE_MAX_C];

    while ((len = get_line(line, LINE_MAX_C)) > 0) {
        lines_total++;
        // 如果长度为1,说明是只有一个换行符的空行，跳过
        if (len == 1)
            continue;
        // 去除字符数组中的空白符，并返回其长度（换行符会被计入长度）
        if ((trimed_len = trim(line)) > 1) {
            copy(line, lines[line_num]);
            line_num++;
        }
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

int trim(char line[])
{
    int i;
    char c;

    for (i = 0; line[i] != '\0'; ++i)
        ;
    // 此时i的值为 '\0'的索引
    for (; (c = line[i]) == '\0' || c == ' ' || c == '\t' || c == '\n'; i--)
        ;
    // 此时i的值为：最后一个非空白字符的索引

    line[++i] = '\n';
    line[i + 1] = '\0';
    // 此时i的值为 '\0'的索引
    return i;
}

void copy(char from[], char to[])
{
    int i;
    for (i = 0; from[i] != '\0'; ++i) 
        to[i] = from[i];
    to[++i] = '\0';
}

