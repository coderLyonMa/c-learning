#include <string.h>
void reverse(char s[]);


void reverse(char s[])
{
    int i = 0;
    
    int n = strlen(s);
    char t[n];

    while (i < n) {
        t[i] = s[n-1-i];
        i++;
    }

    // 此处t不能直接进行*t++这样的操作，因为t不是一个指针，而是一个数组
    // 如果要进行上面这样的操作：需要 char *t = "..."; 这样定义
    for (int i = 0; i < n; i++)
        s[i] = t[i];
}

