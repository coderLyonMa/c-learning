#include <stdio.h>

int trim(char line[]);

int main()
{
    char line[] = "hello world  	\n\0";
    trim(line);


    //for (int i = 0; line[i] != '\0'; i++)
    //    printf("%c", line[i]);
    //trim(line);
    // printf("%s", line);
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
    for (; (c = line[i]) == '\0' || c == ' ' || c == '\t'; i--)
        ;
    // 此时i的值为：最后一个非空白字符的索引

    line[++i] = '\n';
    line[i + 1] = '\0';
    // 此时i的值为 '\0'的索引
    return i;
}

// 这个错误非常经典，看下trim的第二行的声明，导致了怎样的结果————第二个for循环中引用的i的值不仅不符合预期，而且还处于未显式初始化的状况
